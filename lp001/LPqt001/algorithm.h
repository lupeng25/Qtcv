#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "qimage.h"
#include "QDebug"

class Algorithm
{
public:
    Algorithm();
    QImage Mat2QImage(const cv::Mat& mat);
    cv::Mat QImage2cvMat(QImage image);
};

#endif // ALGORITHM_H
