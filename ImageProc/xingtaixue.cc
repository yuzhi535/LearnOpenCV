#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

int main(int argc, char **argv) {
    Mat src = imread("/home/sasuke/Pictures/photo_2021-03-03_18-12-16.jpg");
    Mat blackhat_dst;
    Mat tophat_dst;
    Mat gradient_dst;
    Mat erode_dst;
    Mat dilation_dst;

    namedWindow("src", WINDOW_NORMAL);
    namedWindow("blackhat_dst", WINDOW_NORMAL);
    namedWindow("tophat_dst", WINDOW_NORMAL);
    namedWindow("gradient_dst", WINDOW_NORMAL);
    namedWindow("erode_dst", WINDOW_NORMAL);
    namedWindow("dilation_dst", WINDOW_NORMAL);

    Mat element = getStructuringElement(MORPH_RECT, Size(7, 7));
    morphologyEx(src, blackhat_dst, MORPH_BLACKHAT, element);
    morphologyEx(src, tophat_dst, MORPH_TOPHAT, element);
    morphologyEx(src, gradient_dst, MORPH_GRADIENT, element);
    morphologyEx(src, erode_dst, MORPH_ERODE, element);
    morphologyEx(src, dilation_dst, MORPH_DILATE, element);

    imshow("tophat_dst", tophat_dst);
    imshow("src", src);
    imshow("gradient_dst", gradient_dst);
    imshow("blackhat_dst", blackhat_dst);
    imshow("erode_dst", erode_dst);
    imshow("dilation_dst", dilation_dst);

    waitKey(0);
    return 0;
}