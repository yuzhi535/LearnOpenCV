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
    if (argc < 2) {
        filename = "../images/img2.jpg";
    } else {
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