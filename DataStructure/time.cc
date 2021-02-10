#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

// getTickCount()方法     返回从开始到当前CPU时钟周期数
// getTickFrequency()方法 返回CPU一秒内所走的时钟周期数

int main(int argc, char** argv) {
    double time0 = static_cast<double>(getTickCount());
    Mat img = imread("/home/sasuke/Pictures/img2.jpg");
    namedWindow("asdf");
    imshow("asdf", img);
    waitKey(0);
    printf("%lf seconds \n", (static_cast<double>(getTickCount()) - time0) / getTickFrequency());
    return 0;
}
