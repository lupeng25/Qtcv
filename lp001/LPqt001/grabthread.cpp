#include "grabthread.h"

GrabThread::GrabThread(MvCamera *pMvCamera)
    :m_bThreadState(false)
{
    m_pMvCamera = pMvCamera;

    qRegisterMetaType<QImage>(" QImage&");
}

GrabThread::~GrabThread()
{
//    delete m_pMvCamera;
//    m_pMvCamera = nullptr;
}

void GrabThread::run()
{
    MV_FRAME_OUT stImageInfo = {0};
    int nRet = MV_OK;
    while(m_bThreadState)
    {
        qDebug()<<m_bThreadState;
        nRet = m_pMvCamera->GetImageBuffer(&stImageInfo, 1000);
        if(nRet == MV_OK)
        {
            void* buff = stImageInfo.pBufAddr;
            int width = stImageInfo.stFrameInfo.nWidth;
            int height = stImageInfo.stFrameInfo.nHeight;

            m_pMvCamera->FreeImageBuffer(&stImageInfo);
            cv::Mat Mat_img = cv::Mat(height,width,CV_8UC3,(uchar*)buff);
            cv::cvtColor(Mat_img,Mat_img,cv::COLOR_BGR2RGB);

            Algorithm alg;
            QImage img = alg.Mat2QImage(Mat_img);
//            QImage img = QImage(buff,width,height,QImage::Format_RGB888);
//            cvtColor(image,rgb,CV_BGR2RGB);

//            QImage img;
//            try
//            {
//                cv::Mat matImg;
//                matImg = cv::Mat(height,width,CV_8UC3,buff);
////                cv::cvtColor(matImg,matImg,cv::COLOR_BGR2RGB);
//                Algorithm alg;
//                img = alg.Mat2QImage(matImg);
//            }
//            catch(cv::Exception& e)
//            {
//                qDebug()<<"error";
//            }
//            QImage img(width,height,QImage::Format_Indexed8);
//            {
//                img.setColorCount(256);
//                for(int i=0;i<256;i++)
//                    img.setColor(i,qRgb(i,i,i));
//                uchar *pSrc = reinterpret_cast<uchar*>(buff);
//                for(int row = 0; row<height;row ++)
//                {
//                    uchar *pDest =  img.scanLine(row);
//                    memcpy(pDest,pSrc,static_cast<size_t>(width));
//                    pSrc += width;
//                }
//            }

            emit grabImg(img);


        }


    }
}
