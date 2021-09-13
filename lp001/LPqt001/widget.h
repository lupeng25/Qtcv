#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include "mvcamera.h"
#include "QDebug"
#include "grabthread.h"
#include <QMessageBox>
#include "algorithm.h"
#include "string.h"
#include<iostream>
#include<string>
#include<vector>
#include<opencv.hpp>
#include<QString>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

typedef enum
{
    GrabState_OpenGrab,
    GrabState_CloseGrab,
}GrabState;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    // 打开，关闭设备槽函数
    void slotBtnOpenDevice();
    void slotBtnCloseDevice();
    // 开始停止抓取图像槽函数
    void slotBtnStartGrab();
    void slotBtnStopGrab();
    // 显示图像槽函数
    void slotDisImg(QImage &img);

     void slotbtnGetImage();

    // 保存图像槽函数
    void slotBtnSaveBMP();
    void slotBtnSaveJPG();
    void slotBtnSaveTIFF();
    void slotBtnSavePNG();

    // 相机参数相关槽函数
    void slotBtnGetParam();
    void slotBtnSetParam();

    // g伽马校正相关槽函数
    void slotBtnGetGamma();
    void slotBtnSetGamma();
//   特征检测
    void HumanFea();
    void feaextr();
    QImage faceDect(QImage &img);
    void Camfeature(QImage &img);
    void Camyes();

private:
    void updateState(GrabState ret);

private:
    bool m_bOpenDevice;
private:
    double m_dExposureEdit;  // 曝光时间
    double m_dGainEdit;      // 增益
    double m_dFrameRateEdit; // 帧率
    double m_dGammaEdit; // 伽马值
    int m_dLight;//亮度值
    int m_dSaturation;
    int m_dSharpness;

    int GetExposureTime(); // ch:设置曝光时间 | en:Set Exposure Time
    int SetExposureTime();
    int GetGain();         // ch:设置增益 | en:Set Gain
    int SetGain();
    int GetFrameRate();    // ch:设置帧率 | en:Set Frame Rate
    int SetFrameRate();
    int GetGamma();    // ch:伽马矫正 | en:Set Gamma
    int SetGamma();
    int GetLight();//设置亮度
    int SetLight();
//hsv_setting:
    int SetH();
    int GetH();
    int SetS();
    int GEtS();
    int SetSp();
    int GetSp();


private:
    bool m_bSaveImgBMP;
    bool m_bSaveImgJPG;
    bool m_bSaveImgTIFF;
    bool m_bSaveImgPNG;
    bool m_bUpdateData;
    int  humanfeat=2;
    int camflag=1;
    vector<double> sv;
    int cgflag=0;
    cv::Mat cameraMatrix=cv::Mat::eye(3, 3, CV_64F);
    cv::Mat distCoeffs;
    MvCamera* m_pMvCamera;
    GrabThread* m_pGrabThread;
    Ui::Widget *ui;
};
#endif // WIDGET_H
