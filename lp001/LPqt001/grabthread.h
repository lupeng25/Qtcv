#ifndef GRABTHREAD_H
#define GRABTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include "mvcamera.h"
#include <QImage>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "algorithm.h"

class Algorithm;
class GrabThread
        :public QThread
{
    Q_OBJECT
public:
    GrabThread(MvCamera *pMvCamera);
    ~GrabThread();
    virtual void run();

    inline void setThreadState(bool ret) {m_bThreadState = ret;}
signals:
    void grabImg(QImage& img);

private:
    MvCamera* m_pMvCamera;
    bool m_bThreadState;
};

#endif // GRABTHREAD_H
