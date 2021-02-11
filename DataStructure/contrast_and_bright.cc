/**
 * @file contrast_and_bright.cc
 * @author Zhou YuXi (zhouyuxi@stu.zzu.edu.cn)
 * @brief how to change contrast and brightness of am image. Remember: y = a*x+b, a is contrast, b is brightness
 * @version 0.1
 * @date 2021-02-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

Mat srcImage, dstImage;
int contrastValue, brightnessValue;

void on_contrast_and_brightness(int, void *)
{
    for (int i = 0; i < dstImage.rows; ++i)
    {
        for (int j = 0; j < dstImage.cols; ++j)
        {
            // dstPixel = srcPixel * contrastValue + brightnessValue

            dstImage.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(brightnessValue * 1 + srcImage.at<Vec3b>(i, j)[0] * contrastValue * 0.01);
            dstImage.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(brightnessValue * 1 + srcImage.at<Vec3b>(i, j)[1] * contrastValue * 0.01);
            dstImage.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(brightnessValue * 1 + srcImage.at<Vec3b>(i, j)[2] * contrastValue * 0.01);
        }
    }
    imshow("out", dstImage);
}

int main(int argc, char **argv)
{
    std::string filename;
    if (argc < 2)
    {
        filename = "../images/img2.jpg";
    }
    else
    {
        filename = argv[1];
    }
    srcImage = imread(filename);
    dstImage = Mat::zeros(srcImage.size(), srcImage.type());
    namedWindow("src", WINDOW_NORMAL);
    namedWindow("out", WINDOW_NORMAL);
    imshow("src", srcImage);

    cv::createTrackbar("contrast", "out", &contrastValue, 300, on_contrast_and_brightness);     //not nullptr
    cv::createTrackbar("brightness", "out", &brightnessValue, 300, on_contrast_and_brightness); //not nullptr

    on_contrast_and_brightness(contrastValue, 0);
    on_contrast_and_brightness(brightnessValue, 0);

    waitKey(0);
    return 0;
}