#include "opencv2/opencv.hpp"
#include <iostream>

#define TEST 1

using namespace cv;
using std::cin;
using std::cout;
using std::endl;

int g_value = 3;
Mat dst, cloneImage;

void onChange(int, void *) {
#if TEST == 1
    blur(cloneImage, dst, Size(g_value + 1, g_value + 1));
#elif TEST == 2
    GaussianBlur(cloneImage, dst, Size(g_value * 2 + 1, g_value * 2 + 1), 0);
#elif TEST == 3
    medianBlur(cloneImage, dst, g_value * 2 + 1);
#else
    bilateralFilter(cloneImage, dst, g_value, g_value * 2.0, g_value / 2.0);
#endif
    imshow("dst", dst);
}

int main(int argc, char **argv) {
    Mat src = imread("/home/sasuke/Pictures/photo_2021-03-05_11-12-30.jpg");
    namedWindow("src", WINDOW_NORMAL);   // src
    namedWindow("dst", WINDOW_NORMAL);   // normal
    imshow("src", src);
    cloneImage = src.clone();
    createTrackbar("normal", "dst", &g_value, 40, onChange);
    onChange(g_value, 0);


    waitKey(0);
    return 0;
}