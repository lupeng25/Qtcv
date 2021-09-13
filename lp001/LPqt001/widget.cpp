#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include "string.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include<vector>
#include <sstream>
#include<fstream>
#include<QString>
#include<string>


//txt文件读取及内容转换
void split( string& s, vector<double>& tokens, char delim = ',') {
    tokens.clear();
    ifstream fin;
    fin.open(s);
    string tep;
    fin >> tep;
    fin.close();
    s = tep;
    cout << tep << endl;;
    auto string_find_first_not = [s, delim](size_t pos = 0) -> size_t {
        for (size_t i = pos; i < s.size(); i++) {
            if (s[i] != delim) return i;
        }
        return string::npos;
    };
    size_t lastPos = string_find_first_not(0);
    size_t pos = s.find(delim, lastPos);
    while (lastPos != string::npos) {
        tokens.push_back(stof((s.substr(lastPos, pos - lastPos))));
        lastPos = string_find_first_not(pos);
        pos = s.find(delim, lastPos);
    }
}

//初始化
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , m_bOpenDevice(false)
    , m_pMvCamera(nullptr)
    , m_pGrabThread(nullptr)
    , ui(new Ui::Widget)
    , m_bSaveImgBMP(false)
    , m_bSaveImgJPG(false)
    , m_bSaveImgTIFF(false)
    , m_bSaveImgPNG(false)
    , m_bUpdateData(false)
    ,m_dSharpness(0)
    , m_dLight(0)
    , m_dExposureEdit(0)
    , m_dGainEdit(0)
    , m_dFrameRateEdit(0)
    , m_dGammaEdit(0)

{
    ui->setupUi(this);

    // 点击“开始抓图”， 开始抓取图像
    connect(ui->btnStartGrab,&QPushButton::clicked,this,&Widget::slotBtnStartGrab);
    // 点击“停止抓图”， 停止抓取图像
    connect(ui->btnStopGrab,&QPushButton::clicked,this,&Widget::slotBtnStopGrab);

    // 点击“保存图像”，开始保存图像
    connect(ui->btnSaveBMP,&QPushButton::clicked,this,&Widget::slotBtnSaveBMP);
    connect(ui->btnSaveJPG,&QPushButton::clicked,this,&Widget::slotBtnSaveJPG);
    connect(ui->btnSaveTIFF,&QPushButton::clicked,this,&Widget::slotBtnSaveTIFF);
    connect(ui->btnSavePNG,&QPushButton::clicked,this,&Widget::slotBtnSavePNG);

    connect(ui->btnCloseWin,&QPushButton::clicked,this,&Widget::close);

    // 点击“参数获取”，获取相机参数
    connect(ui->B_getParam,&QPushButton::clicked,this,&Widget::slotBtnGetParam);
    // 点击“参数设置”，设置相机参数
    connect(ui->B_setParam,&QPushButton::clicked,this,&Widget::slotBtnSetParam);

    // 点击“参数获取”，获取gamma值
    connect(ui->B_getGamma,&QPushButton::clicked,this,&Widget::slotBtnGetGamma);
    // 点击“伽马校正”，进行伽马校正
    connect(ui->B_setGamma,&QPushButton::clicked,this,&Widget::slotBtnSetGamma);
     //
    connect(ui->btnGetImage,&QPushButton::clicked,this,&Widget::slotbtnGetImage);
    connect(ui->btnFeature,&QPushButton::clicked,this,&Widget::feaextr);
    connect(ui->human,&QPushButton::clicked,this,&Widget::HumanFea);
    connect(ui->Camfea,&QPushButton::clicked,this,&Widget::Camyes);
    updateState(GrabState_CloseGrab);
}

Widget::~Widget()
{
    delete ui;
}


//设备开关
void Widget::slotBtnOpenDevice()
{

    if(true == m_bOpenDevice || m_pMvCamera != nullptr)
    {
        qDebug()<<"is open Device";
        return;
    }


    // get current link camera
    MV_CC_DEVICE_INFO_LIST  m_stDevList;
    int nRet = MvCamera::EnumDevices(MV_USB_DEVICE , &m_stDevList);
    if (MV_OK != nRet)
    {
        qDebug()<<"get Camera Error";
        return;
    }

    m_pMvCamera = new MvCamera;
    if(nullptr == m_pMvCamera)
        return;

    nRet = m_pMvCamera->Open(m_stDevList.pDeviceInfo[0]);
    if (MV_OK != nRet)
    {
        delete m_pMvCamera;
        m_pMvCamera = nullptr;
        qDebug()<<"Open Fail";
        return;
    }

    qDebug()<<"Open success";
    m_bOpenDevice = true;
}
void Widget::slotBtnCloseDevice()
{
    if(m_pMvCamera != nullptr)
    {
        m_pMvCamera->Close();

        delete m_pMvCamera;
        m_pMvCamera = nullptr;
        qDebug()<<"close success";
        m_bOpenDevice = false;
    }
    else
       qDebug()<<"device is not create";
}


//图像抓取
void Widget::slotBtnStartGrab()
{
    slotBtnOpenDevice();
    QThread::msleep(500);
    if(!m_bOpenDevice )
    {
        QMessageBox::information(this,"error","device is not open");
        return;
    }

    m_pGrabThread = new GrabThread(m_pMvCamera);

    connect(m_pGrabThread,&GrabThread::grabImg,this,&Widget::slotDisImg);
     connect(m_pGrabThread,&GrabThread::grabImg,this,&Widget::faceDect);

    int nRet = m_pMvCamera->StartGrabbing();

    if (MV_OK != nRet)
    {
        qDebug()<<"Start grabbing fail : "<< nRet;
        return;
    }
    qDebug()<<"Start grabbing sussess";

    m_pGrabThread->setThreadState(true);
    m_pGrabThread->start();

    updateState(GrabState_OpenGrab);


}

void Widget::slotBtnStopGrab()
{
    if(true != m_bOpenDevice || m_pMvCamera == nullptr|| m_pGrabThread == nullptr)
    {
        return;
    }

    m_pGrabThread->setThreadState(false);
    m_pGrabThread->wait();
    m_pGrabThread->quit();
    disconnect(m_pGrabThread,&GrabThread::grabImg,this,&Widget::slotDisImg);
    ///////////////////////////////////////////////////////////////////////////////ss//
    disconnect(m_pGrabThread,&GrabThread::grabImg,this,&Widget::faceDect);

    int nRet = m_pMvCamera->StopGrabbing();

    delete m_pGrabThread;
//    m_pGrabThread->deleteLater();
    m_pGrabThread = nullptr;

    if (MV_OK != nRet)
    {
        qDebug()<<"Stop grabbing fail";
        return;
    }
    qDebug()<<"Stop grabbing sussess";

    QThread::msleep(500);

    slotBtnCloseDevice();

    updateState(GrabState_CloseGrab);

}

void Widget::slotDisImg(QImage &img)
{
    qDebug()<<"slot frame";
    ui->label->clear();
//    img = img.scaled(ui->label->width(), ui->label->height());
    img = img.scaled(ui->label->size(),Qt::IgnoreAspectRatio);
    ui->label->setScaledContents(true);

    Algorithm alg;
    cv::Mat matImg = alg.QImage2cvMat(img);

//    cv::threshold(matImg,matImg,128,255,1);

    QImage retImg = alg.Mat2QImage(matImg);

    if(this->cgflag==0){
         ui->label->setPixmap(QPixmap::fromImage(retImg));
    }else if (this->cgflag==1) {
        undistort(matImg, matImg, cameraMatrix, distCoeffs);
        retImg = alg.Mat2QImage(matImg);
        ui->label->setPixmap(QPixmap::fromImage(retImg));
}
    if(m_bSaveImgBMP == true)
    {
        m_bSaveImgBMP = false;
        // add code to save img
        QString filename = QFileDialog::getSaveFileName(NULL, tr("Save Image"), "", tr("Images (*.bmp)"));
        cv::imwrite(filename.toStdString(), matImg);
    }
    if(m_bSaveImgJPG == true)
    {
        m_bSaveImgJPG = false;
        // add code to save img
        QString filename = QFileDialog::getSaveFileName(NULL, tr("Save Image"), "", tr("Images (*.jpg)"));
        cv::imwrite(filename.toStdString(), matImg);
    }
    if(m_bSaveImgTIFF == true)
    {
        m_bSaveImgTIFF = false;
        // add code to save img
        QString filename = QFileDialog::getSaveFileName(NULL, tr("Save Image"), "", tr("Images (*.tiff)"));
        cv::imwrite(filename.toStdString(), matImg);
    }
    if(m_bSaveImgPNG == true)
    {
        m_bSaveImgPNG = false;
        // add code to save img
        QString filename = QFileDialog::getSaveFileName(NULL, tr("Save Image"), "", tr("Images (*.png)"));
        cv::imwrite(filename.toStdString(), matImg);
    }

}



//特征提取
void Widget::Camyes()
{
    this->camflag=1;
}
void Widget::Camfeature(QImage &img)
{
    img = img.scaled(ui->label->size(),Qt::IgnoreAspectRatio);
    ui->label->setScaledContents(true);

    Algorithm alg;
    cv::Mat src = alg.QImage2cvMat(img);

    QStringList listTemp;
    if(this->camflag==1){
     cv::Mat GaussImg;
     //medianBlur(src, GaussImg,5);//中值滤波
     GaussianBlur(src, GaussImg, cv::Size(7, 7), 0, 0);//高斯滤波
     //imshow("Gauss Image", GaussImg);
     cvtColor(GaussImg, GaussImg, cv::COLOR_BGR2GRAY);

     //二值化操作
     cv::Mat binary;
     threshold(GaussImg, binary, 128, 255, cv::THRESH_BINARY);
     //cv::namedWindow("binary Image", 0);
     //imshow("binary Image", binary);

     //形态学操作
     cv::Mat morphImg;
     cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5), cv::Point(-1, -1));
     morphologyEx(binary, morphImg, cv::MORPH_CLOSE, kernel,cv:: Point(-1, -1), 1);
     //imshow("morph Image", morphImg);

     //阈值分割
     cv::Mat contoursIm;
     threshold(morphImg, contoursIm, 0, 255, cv::THRESH_BINARY + cv::THRESH_OTSU);
     //imshow("阈值分割", contoursIm);


     //轮廓发现
     cv::Mat contoursImg = cv::Mat::zeros(src.size(), CV_8UC3);
     vector<vector<cv::Point>>contours;//存储二维浮点型向量，这里面将来会存储找到du的边界的（x,y）坐标
     vector<cv::Vec4i>hierarchy;//定义的层级。这个在找边界findcontours的时候会自动生成，这里只是给它开辟一个空间

     findContours(contoursIm, contours, cv::RETR_LIST,cv:: CHAIN_APPROX_NONE);//保存物体边界上所有连续的轮廓点到contours向量内
     int flags = 0;
     for (size_t i = 0; i < contours.size(); i++)
     {
         cv::Rect rect = boundingRect(contours[i]);

         if (rect.height == src.rows)
         {
             flags = 1;
             contours.pop_back();
         }


         if (flags == 0)
         {
             drawContours(contoursImg, contours, static_cast<int>(i), cv::Scalar(0, 0, 255), 2, 8, hierarchy, 0,cv:: Point(0, 0));
         }
         flags = 0;
     }

     vector<cv::Point>triangle;
     vector<cv::Point>approx;
     vector<cv::Point>squares;

     vector<cv::Vec3f>circles;//圆
     HoughCircles(GaussImg, circles, cv::HOUGH_GRADIENT, 1, src.rows / 20, 100, 60, 0, 0);//rows/20为检测圆之间距离，100为传递给canny边缘检测算子的高阈值，60（它越小则可以检测到更多跟本不存在的圆，两个0为半径默认值）

     cv::Mat dstImg(morphImg.rows, morphImg.cols, CV_8UC3, cv::Scalar(255, 255, 255));
     for (size_t i = 0; i < circles.size(); i++)//画圆
     {
         cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
         int radius = cvRound(circles[i][2]);
         QString rl1="圆形"+QString::number(i + 1)+"中心: X"+QString::number(center.x)+" ,Y"+QString::number(center.y);
         QString rl2="圆形"+QString::number(i + 1)+"的面积为："+QString::number(3.14 * radius * radius);
         QString rl3="圆形"+QString::number(i + 1)+"的周长为："+QString::number(3.14 * 2 * radius );
         listTemp.append(rl1+"\n"+rl2+"\n"+rl3);

     }

     //多边形拟合操作
     for (size_t i = 0; i < contours.size(); i++)
     {
         approxPolyDP(contours[i], approx, arcLength(cv::Mat(contours[i]), true) * 0.02, true);                     //主要功能是把一个连续光滑曲线折线化，对图像轮廓点进行多边形拟合。
         if (approx.size() == 4 && fabs(contourArea(cv::Mat(approx))) > 1000 && isContourConvex(cv::Mat(approx)))
         {
             double minDist = 1e10;

             for (int i = 0; i < 4; i++)
             {
                 cv::Point side = approx[i] - approx[(i + 1) % 4];
                 double squaredSideLength = side.dot(side);
                 minDist = min(minDist, squaredSideLength);
             }
             if (minDist < 50)
                 break;
             for (int i = 0; i < 4; i++)
                 squares.push_back(cv::Point(approx[i].x, approx[i].y));
         }

         approxPolyDP(contours[i], approx, arcLength(cv::Mat(contours[i]), true) * 0.1, true);
         if (approx.size() == 3 && fabs(contourArea(cv::Mat(approx))) > 1000 && isContourConvex(cv::Mat(approx)))
         {
             double minDist = 1e10;

             for (int i = 0; i < 3; i++)
             {
                 cv::Point side = approx[i] - approx[(i + 1) % 3];
                 double squaredSideLength = side.dot(side);
                 minDist = min(minDist, squaredSideLength);
             }
             if (minDist < 50)
                 break;
             for (int i = 0; i < 3; i++)
                 triangle.push_back(cv::Point(approx[i].x, approx[i].y));
         }
         drawContours(dstImg, contours, i, cv::Scalar(0, 0, 255), 3);
     }

     for (size_t i = 0; i < squares.size(); i += 4)//描边操作
     {
         cv::Point center;
         center.x = (squares[i].x + squares[i + 2].x) / 2;
         center.y = (squares[i].y + squares[i + 2].y) / 2;
         line(dstImg, squares[i], squares[i + 1], cv::Scalar(255, 0, 255), 4);
         line(dstImg, squares[i + 1], squares[i + 2], cv::Scalar(255, 0, 255), 4);
         line(dstImg, squares[i + 2], squares[i + 3],cv:: Scalar(255, 0, 255), 4);
         line(dstImg, squares[i + 3], squares[i], cv::Scalar(255, 0, 255), 4);
         QString l1="矩形"+QString::number((i + 1) % 4)+"中心"+QString::number(center.x)+" ,"+QString::number(center.y);
         QString l2="矩形"+QString::number(i + 1)+"的面积为："+QString::number(contourArea(squares));
         QString l3="矩形"+QString::number(i + 1)+"的周长为："+QString::number(arcLength(squares, true) );
         listTemp.append(l1+"\n"+l2+"\n"+l3+"\n");

     }


     for (size_t i = 0; i < triangle.size(); i += 3)
     {
         cv::Point center;
         center.x = (triangle[i].x + triangle[i + 1].x + triangle[i + 2].x) / 3;
         center.y = (triangle[i].y + triangle[i + 1].y + triangle[i + 2].y) / 3;
         QString tl1="三角形"+QString::number((i + 1) % 3)+"中心:X"+QString::number(center.x)+" ,Y"+QString::number(center.y);
         QString tl2="三角形"+QString::number(i + 1)+"的面积为："+QString::number(contourArea(triangle));
         QString tl3="三角形"+QString::number(i + 1)+"的周长为："+QString::number(arcLength(triangle, 1) );
         listTemp.append(tl1+"\n"+tl2+"\n"+tl3+"\n");
     }
     QString str = listTemp.join(";");
     ui->label_233->setPlainText(str);
    }
}

void  Widget::feaextr(){
       string feaname=(ui->featureline->text()).toStdString();
       QStringList listTemp;
       cv::Mat src = cv::imread(feaname);
        if (src.empty())
        {
            printf("图片未找到!!!");
            return ;
        }
        //imshow("input image", src);
        //高斯模糊
        cv::Mat GaussImg;
        //medianBlur(src, GaussImg,5);//中值滤波
        GaussianBlur(src, GaussImg, cv::Size(7, 7), 0, 0);//高斯滤波
        //imshow("Gauss Image", GaussImg);
        cvtColor(GaussImg, GaussImg, cv::COLOR_BGR2GRAY);

        //二值化操作
        cv::Mat binary;
        threshold(GaussImg, binary, 128, 255, cv::THRESH_BINARY);
        //cv::namedWindow("binary Image", 0);
        //imshow("binary Image", binary);

        //形态学操作
        cv::Mat morphImg;
        cv::Mat kernel = getStructuringElement(cv::MORPH_RECT, cv::Size(5, 5), cv::Point(-1, -1));
        morphologyEx(binary, morphImg, cv::MORPH_CLOSE, kernel,cv:: Point(-1, -1), 1);
        //imshow("morph Image", morphImg);

        //阈值分割
        cv::Mat contoursIm;
        threshold(morphImg, contoursIm, 0, 255, cv::THRESH_BINARY + cv::THRESH_OTSU);
        //imshow("阈值分割", contoursIm);


        //轮廓发现
        cv::Mat contoursImg = cv::Mat::zeros(src.size(), CV_8UC3);
        vector<vector<cv::Point>>contours;//存储二维浮点型向量，这里面将来会存储找到du的边界的（x,y）坐标
        vector<cv::Vec4i>hierarchy;//定义的层级。这个在找边界findcontours的时候会自动生成，这里只是给它开辟一个空间

        findContours(contoursIm, contours, cv::RETR_LIST,cv:: CHAIN_APPROX_NONE);//保存物体边界上所有连续的轮廓点到contours向量内
        int flags = 0;
        for (size_t i = 0; i < contours.size(); i++)
        {
            cv::Rect rect = boundingRect(contours[i]);

            if (rect.height == src.rows)
            {
                flags = 1;
                contours.pop_back();
            }


            if (flags == 0)
            {
                drawContours(contoursImg, contours, static_cast<int>(i), cv::Scalar(0, 0, 255), 2, 8, hierarchy, 0,cv:: Point(0, 0));
            }
            flags = 0;
        }

        vector<cv::Point>triangle;
        vector<cv::Point>approx;
        vector<cv::Point>squares;

        vector<cv::Vec3f>circles;//圆
        HoughCircles(GaussImg, circles, cv::HOUGH_GRADIENT, 1, src.rows / 20, 100, 60, 0, 0);//rows/20为检测圆之间距离，100为传递给canny边缘检测算子的高阈值，60（它越小则可以检测到更多跟本不存在的圆，两个0为半径默认值）

        cv::Mat dstImg(morphImg.rows, morphImg.cols, CV_8UC3, cv::Scalar(255, 255, 255));
        for (size_t i = 0; i < circles.size(); i++)//画圆
        {
            cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
//            circle(dstImg, center, radius, Scalar(0, 255, 0), 5, 8, 0);
//            circle(dstImg, center, 3, Scalar(0, 255, 0), -1);
            QString rl1="圆形"+QString::number(i + 1)+"中心: X"+QString::number(center.x)+" ,Y"+QString::number(center.y);
            QString rl2="圆形"+QString::number(i + 1)+"的面积为："+QString::number(3.14 * radius * radius);
            QString rl3="圆形"+QString::number(i + 1)+"的周长为："+QString::number(3.14 * 2 * radius );
            listTemp.append(rl1+"\n"+rl2+"\n"+rl3);
//            cout << "圆形" << i + 1 << "中心" << center << endl;
//            cout << "圆" << i + 1 << "的面积为：" << 3.14 * radius * radius << endl;
//            cout << "圆" << i + 1 << "的周长为：" << 3.14 * 2 * radius << endl;
        }

        //多边形拟合操作
        for (size_t i = 0; i < contours.size(); i++)
        {
            approxPolyDP(contours[i], approx, arcLength(cv::Mat(contours[i]), true) * 0.02, true);                     //主要功能是把一个连续光滑曲线折线化，对图像轮廓点进行多边形拟合。
            if (approx.size() == 4 && fabs(contourArea(cv::Mat(approx))) > 1000 && isContourConvex(cv::Mat(approx)))
            {
                double minDist = 1e10;

                for (int i = 0; i < 4; i++)
                {
                    cv::Point side = approx[i] - approx[(i + 1) % 4];
                    double squaredSideLength = side.dot(side);
                    minDist = min(minDist, squaredSideLength);
                }
                if (minDist < 50)
                    break;
                for (int i = 0; i < 4; i++)
                    squares.push_back(cv::Point(approx[i].x, approx[i].y));
            }

            approxPolyDP(contours[i], approx, arcLength(cv::Mat(contours[i]), true) * 0.1, true);
            if (approx.size() == 3 && fabs(contourArea(cv::Mat(approx))) > 1000 && isContourConvex(cv::Mat(approx)))
            {
                double minDist = 1e10;

                for (int i = 0; i < 3; i++)
                {
                    cv::Point side = approx[i] - approx[(i + 1) % 3];
                    double squaredSideLength = side.dot(side);
                    minDist = min(minDist, squaredSideLength);
                }
                if (minDist < 50)
                    break;
                for (int i = 0; i < 3; i++)
                    triangle.push_back(cv::Point(approx[i].x, approx[i].y));
            }
            drawContours(dstImg, contours, i, cv::Scalar(0, 0, 255), 3);
        }

        for (size_t i = 0; i < squares.size(); i += 4)//描边操作
        {
            cv::Point center;
            center.x = (squares[i].x + squares[i + 2].x) / 2;
            center.y = (squares[i].y + squares[i + 2].y) / 2;
            line(dstImg, squares[i], squares[i + 1], cv::Scalar(255, 0, 255), 4);
            line(dstImg, squares[i + 1], squares[i + 2], cv::Scalar(255, 0, 255), 4);
            line(dstImg, squares[i + 2], squares[i + 3],cv:: Scalar(255, 0, 255), 4);
            line(dstImg, squares[i + 3], squares[i], cv::Scalar(255, 0, 255), 4);
            QString l1="矩形"+QString::number((i + 1) % 4)+"中心"+QString::number(center.x)+" ,"+QString::number(center.y);
            QString l2="矩形"+QString::number(i + 1)+"的面积为："+QString::number(contourArea(squares));
            QString l3="矩形"+QString::number(i + 1)+"的周长为："+QString::number(arcLength(squares, true) );
            listTemp.append(l1+"\n"+l2+"\n"+l3+"\n");
//            ui->label_233->setPlainText(l1+"\n"+l2+"\n"+l3);
//            cout << "矩形" << (i + 1) % 4 << "中心" << center << endl;
//            cout << "矩形" << i + 1 << "的面积为：" << contourArea(squares) << endl;
//            cout << "矩形" << i + 1 << "的周长为：" << arcLength(squares, true) << endl;
//            circle(dstImg, center, 3, cv::Scalar(255, 0, 255), -1);
        }


        for (size_t i = 0; i < triangle.size(); i += 3)
        {
            cv::Point center;
            center.x = (triangle[i].x + triangle[i + 1].x + triangle[i + 2].x) / 3;
            center.y = (triangle[i].y + triangle[i + 1].y + triangle[i + 2].y) / 3;
//            line(dstImg, triangle[i], triangle[i + 1], cv::Scalar(255, 0, 0), 4);
//            line(dstImg, triangle[i + 1], triangle[i + 2], cv::Scalar(255, 0, 0), 4);
//            line(dstImg, triangle[i], triangle[i + 2], cv::Scalar(255, 0, 0), 4);
//            cout << "三角形" << (i + 1) % 3 << "中心" << center << endl;
//            cout << "三角形" << i + 1 << "的面积为：" << contourArea(triangle) << endl;
//            cout << "三角形" << i + 1 << "的周长为：" << arcLength(triangle, 1) << endl;
            QString tl1="三角形"+QString::number((i + 1) % 3)+"中心:X"+QString::number(center.x)+" ,Y"+QString::number(center.y);
            QString tl2="三角形"+QString::number(i + 1)+"的面积为："+QString::number(contourArea(triangle));
            QString tl3="三角形"+QString::number(i + 1)+"的周长为："+QString::number(arcLength(triangle, 1) );
//            circle(dstImg, center, 3, cv::Scalar(255, 0, 0), -1);
            listTemp.append(tl1+"\n"+tl2+"\n"+tl3+"\n");
        }
        QString str = listTemp.join(";");
        ui->label_233->setPlainText(str);

        //显示提取图像
//       cv:: Mat extract(src.size(), CV_8UC3, cv::Scalar(255, 255, 255));
//        for (size_t i = 0; i < squares.size(); i += 4)//描边操作
//        {
//            cv::Point center;
//            center.x = (squares[i].x + squares[i + 2].x) / 2;
//            center.y = (squares[i].y + squares[i + 2].y) / 2;
//            line(extract, squares[i], squares[i + 1], cv::Scalar(255, 0, 255), 4);
//            line(extract, squares[i + 1], squares[i + 2],cv:: Scalar(255, 0, 255), 4);
//            line(extract, squares[i + 2], squares[i + 3], cv::Scalar(255, 0, 255), 4);
//            line(extract, squares[i + 3], squares[i], cv::Scalar(255, 0, 255), 4);
//            circle(extract, center, 3, cv::Scalar(255, 0, 255), -1);
//        }
}
void  Widget::faceDect(QImage &img)
{
    string facede="H:\downloader\OpenCV\etc\haarcascades\haarcascade_frontalface_default.xml";
    //string eysde="H:\downloader\OpenCV\etc\haarcascades\haarcascade_eye.xml";
    string fullde="H:\downloader\OpenCV\etc\haarcascades\haarcascade_fullbody.xml";
    cv::CascadeClassifier Classifier;
    switch(this->humanfeat){
//    case 1:
//      Classifier.load(eysde);
//        break;
    case 1:
       Classifier.load(facede);
        break;
     case 2:
        Classifier.load(fullde);
    }

    qDebug()<<"slot frame";
    ui->label_5->clear();
    img = img.scaled(ui->label_5->size(),Qt::IgnoreAspectRatio);
    ui->label_5->setScaledContents(true);
    Algorithm alg;
    vector<cv::Rect> faces;
    cv::Mat matImg = alg.QImage2cvMat(img);
    Classifier.detectMultiScale(matImg, faces, 1.1, 3, 0, cv::Size(30, 30));
    for (size_t t = 0; t < faces.size(); t++)
         {
           rectangle(matImg, faces[t], cv::Scalar(0, 255, 0), 2, 8);//画个绿框
         }

    QImage retImg = alg.Mat2QImage(matImg);
    ui->label_5->setPixmap(QPixmap::fromImage(retImg));

}
void Widget::slotbtnGetImage()
{

        string filename;
        filename=(ui->BdEdit->text()).toStdString();
        this->sv.clear();
        split(filename,this->sv,',');
        this->cameraMatrix.at<double>(0, 0) = sv[0];
        this->cameraMatrix.at<double>(0, 1) = sv[1];
        this->cameraMatrix.at<double>(0, 2) = sv[2];
        this->cameraMatrix.at<double>(1, 1) = sv[3];
        this->cameraMatrix.at<double>(1, 2) = sv[4];

        this->distCoeffs = cv::Mat::zeros(5, 1, CV_64F);
        distCoeffs.at<double>(0, 0) = sv[5];
        distCoeffs.at<double>(1, 0) = sv[6];
        distCoeffs.at<double>(2, 0) = sv[7];
        distCoeffs.at<double>(3, 0) = sv[8];
        distCoeffs.at<double>(4, 0) = sv[9];
        this->cgflag=1;
}
void Widget::HumanFea()
{
   int tep=ui->humanfeature->toPlainText().toInt();
   this->humanfeat=tep;
}


/////////////////////////////// 设置相机参数
int Widget::GetExposureTime()
{
    MVCC_FLOATVALUE stFloatValue = {0};

        int nRet = m_pMvCamera->GetFloatValue("ExposureTime", &stFloatValue);
        if (MV_OK != nRet)
        {
            return nRet;
        }

        m_dExposureEdit = stFloatValue.fCurValue;
        QString exposure_str = QString::number(m_dExposureEdit, 'f', 2);
        ui->B__expose->setPlainText(exposure_str);
        return MV_OK;
}

int Widget::SetExposureTime()
{
    // ch:调节这两个曝光模式，才能让曝光时间生效
        int nRet = m_pMvCamera->SetEnumValue("ExposureMode", MV_EXPOSURE_MODE_TIMED);
        if (MV_OK != nRet)
        {
            return nRet;
        }

        m_pMvCamera->SetEnumValue("ExposureAuto", MV_EXPOSURE_AUTO_MODE_OFF);
        m_dExposureEdit = ui->B__expose->toPlainText().toDouble();
        return m_pMvCamera->SetFloatValue("ExposureTime", (float)m_dExposureEdit);
}

int Widget::GetGain()
{
    MVCC_FLOATVALUE stFloatValue = {0};
        int nRet = m_pMvCamera->GetFloatValue("Gain", &stFloatValue);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dGainEdit = stFloatValue.fCurValue;
        QString gain_str = QString::number(m_dGainEdit, 'f', 2);
        ui->B__gamma_2->setPlainText(gain_str);
        return MV_OK;
}

int Widget::SetGain()
{
    // ch:设置增益前先把自动增益关闭，失败无需返回
        m_pMvCamera->SetEnumValue("GainAuto", 100);
        m_dGainEdit = ui->B__gamma_2->toPlainText().toDouble();
        return m_pMvCamera->SetFloatValue("Gain", (float)m_dGainEdit);
}

int Widget::GetFrameRate()
{
    MVCC_FLOATVALUE stFloatValue = {0};
        int nRet = m_pMvCamera->GetFloatValue("ResultingFrameRate", &stFloatValue);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dFrameRateEdit = stFloatValue.fCurValue;
        QString frameRate_str = QString::number(m_dFrameRateEdit, 'f', 2);
        ui->B__fps->setPlainText(frameRate_str);
        return MV_OK;
}

int Widget::SetFrameRate()
{
    int nRet = m_pMvCamera->SetBoolValue("AcquisitionFrameRateEnable", true);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dFrameRateEdit = ui->B__fps->toPlainText().toDouble();
        return m_pMvCamera->SetFloatValue("AcquisitionFrameRate", (float)m_dFrameRateEdit);
}
int Widget::GetLight()
{
    MVCC_INTVALUE stIntValue = {0};
        int nRet = m_pMvCamera->GetIntValue("Brightness",&stIntValue);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dLight =stIntValue.nCurValue;
        QString light_str = QString::number(m_dLight, 'f', 2);
        ui->B_light->setPlainText(light_str);
        return MV_OK;
}
int Widget::SetLight()
{
    int nRet = m_pMvCamera->SetBoolValue("BrightnessEnable", true);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dLight = ui->B_light->toPlainText().toInt();
        return m_pMvCamera->SetIntValue("Brightness", (int)m_dLight);
}
int Widget::GetSp()
{
    MVCC_INTVALUE stIntValue = {0};
        int nRet = m_pMvCamera->GetIntValue("Sharpness",&stIntValue);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dSharpness =stIntValue.nCurValue;
        QString sharpness_str = QString::number(m_dSharpness, 'f', 2);
        ui->B_Sp->setPlainText(sharpness_str);
        return MV_OK;
}
int Widget::SetSp()
{
    int nRet = m_pMvCamera->SetBoolValue("SharpnessEnable", true);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dSharpness = ui->B_Sp->toPlainText().toInt();
        return m_pMvCamera->SetIntValue("Sharpness", (int)m_dSharpness);
}
int Widget::GetGamma()
{
    MVCC_FLOATVALUE stFloatValue = {0};
        int nRet = m_pMvCamera->GetFloatValue("Gamma", &stFloatValue);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dGammaEdit = stFloatValue.fCurValue;
        QString gamma_str = QString::number(m_dGammaEdit, 'f', 2);
        ui->B__Gamma->setPlainText(gamma_str);
        return MV_OK;
}

int Widget::SetGamma()
{
    int nRet = m_pMvCamera->SetBoolValue("GammaEnable", true);
        if (MV_OK != nRet)
        {
            return nRet;
        }
        m_dGammaEdit = ui->B__Gamma->toPlainText().toDouble();
        return m_pMvCamera->SetFloatValue("Gamma", (float)m_dGammaEdit);
}

//////////////////////////////////////


void Widget::slotBtnGetGamma()
{
    int nRet = GetGamma();
        if (nRet != MV_OK)
        {
            QMessageBox::information(this,"error","Get Gamma Fail");
        }
        m_bUpdateData = false;
}

void Widget::slotBtnSetGamma()
{
    m_bUpdateData = true;

        bool bIsSetSucceed = true;
        int nRet = SetGamma();
        if (nRet != MV_OK)
        {
            bIsSetSucceed = false;
            QMessageBox::information(this,"error","设置伽马校正失败, gamma取值范围：0~4");

        }

        if (true == bIsSetSucceed)
        {
            QMessageBox::information(this,"Succeed","Gamma Correction Succeed");
        }
}
void Widget::slotBtnGetParam()
{
    int nRet = GetExposureTime();
        if (nRet != MV_OK)
        {
            QMessageBox::information(this,"error","Get Exposure Time Fail");
        }

        nRet = GetGain();
        if (nRet != MV_OK)
        {
            QMessageBox::information(this,"error","Get Gain Fail");
        }

        nRet = GetFrameRate();
        if (nRet != MV_OK)
        {
            QMessageBox::information(this,"error","Get Frame Rate Fail");
        }
        nRet=GetLight();
        if (nRet != MV_OK)
        {
            QMessageBox::information(this,"error","Get Brightness Fail");
        }
        nRet=GetSp();
        if (nRet != MV_OK)
        {
            QMessageBox::information(this,"error","Get Sharpness Fail");
        }
        m_bUpdateData = false;
}

void Widget::slotBtnSetParam()
{
    m_bUpdateData = true;

        bool bIsSetSucceed = true;
        int nRet = SetExposureTime();
        if (nRet != MV_OK)
        {
            bIsSetSucceed = false;
            QMessageBox::information(this,"error","Set Exposure Time Fail");

        }
        nRet = SetGain();
        if (nRet != MV_OK)
        {
            bIsSetSucceed = false;
            QMessageBox::information(this,"error","设置增益失败，增益范围：0~15.0062");
        }
        nRet = SetFrameRate();
        if (nRet != MV_OK)
        {
            bIsSetSucceed = false;
            QMessageBox::information(this,"error","Set Frame Rate Fail");
        }
        nRet=SetLight();
        if (nRet != MV_OK)
        {
            bIsSetSucceed = false;
            QMessageBox::information(this,"error","Set Brightness Fail");
        }
       nRet=SetSp();
        if (nRet != MV_OK)
        {
            bIsSetSucceed = false;
            QMessageBox::information(this,"error","Set Sharpness Fail");
        }
        if (true == bIsSetSucceed)
        {
            QMessageBox::information(this,"Succeed","Set Parameter Succeed");
        }
}

void Widget::updateState(GrabState ret)
{
    if(ret == GrabState_OpenGrab)
    {
        ui->btnCloseWin->setEnabled(false);
        ui->B_getParam->setEnabled(true);
        ui->B_setParam->setEnabled(true);
        ui->B_getGamma->setEnabled(true);
        ui->B_setGamma->setEnabled(true);
        ui->btnSaveBMP->setEnabled(true);
        ui->btnSaveJPG->setEnabled(true);
        ui->btnSaveTIFF->setEnabled(true);
        ui->btnSavePNG->setEnabled(true);
        ui->btnGetImage->setEnabled(true);
        ui->Camfea->setEnabled(true);
        ui->btnGetImage->setEnabled(true);
    }
    else
    {
        ui->btnCloseWin->setEnabled(true);
        ui->B_getParam->setEnabled(false);
        ui->B_setParam->setEnabled(false);
        ui->B_getGamma->setEnabled(false);
        ui->B_setGamma->setEnabled(false);
        ui->btnSaveBMP->setEnabled(false);
        ui->btnSaveJPG->setEnabled(false);
        ui->btnSaveTIFF->setEnabled(false);
        ui->btnSavePNG->setEnabled(false);
        ui->Camfea->setEnabled(false);
        ui->btnGetImage->setEnabled(false);
        ui->btnGetImage->setEnabled(true);
    }
}


//图像存储
void Widget::slotBtnSaveBMP()
{
    m_bSaveImgBMP = true;
}
void Widget::slotBtnSaveJPG()
{
    m_bSaveImgJPG = true;
}
void Widget::slotBtnSaveTIFF()
{
    m_bSaveImgTIFF = true;
}
void Widget::slotBtnSavePNG()
{
    m_bSaveImgPNG= true;
}
