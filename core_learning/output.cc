/* 输出numpy风格 */

#include <opencv2/opencv.hpp>
#include <bits/stdc++.h>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat mat(3, 3, CV_8UC3, Scalar(0, 0, 255));
    // numpy
    cout << "numpy\n" << format(mat, Formatter::FMT_NUMPY) << endl;
    //python
    cout << "python\n" << format(mat, Formatter::FMT_PYTHON) << endl;
    return 0;
}