#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
#define DST1 0
#define DST2 0
#define DST3 1

int main(int argc, char **argv)
{
	Mat srcImage = imread("/home/sasuke/Pictures/img2.jpg");
	// 用指针访问
	Mat dst = srcImage.clone();

	double time0 = static_cast<double>(getTickCount());
#if DST1 == 1
	for (int i = 0; i < dst.rows; ++i)
	{
		auto data = dst.ptr<uchar>(i);
		for (int j = 0; j < dst.cols * dst.channels(); ++j)
		{
			data[j] /= 2;
		}
	}
#endif
#if DST2 == 1
	// 迭代器法
	Mat_<Vec3b>::iterator it = dst.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = dst.end<Vec3b>();

	for (; it != itend; ++it)
	{
		(*it)[0] /= 2;
		(*it)[1] /= 2;
		(*it)[2] /= 2;
	}

#endif
#if DST3 == 1
	// 动态地址法
	// rgb  opencv比较奇怪
	for (int i = 0; i < dst.rows; ++i)
	{
		for (int j = 0; j < dst.cols; ++j)
		{
			dst.at<Vec3b>(i, j)[0] /= 2;
			dst.at<Vec3b>(i, j)[1] /= 2;
			dst.at<Vec3b>(i, j)[2] /= 2;
		}
	}
#endif
	double time1 = static_cast<double>(getTickCount());
	namedWindow("src", WINDOW_NORMAL);
	namedWindow("output", WINDOW_NORMAL);
	imshow("src", srcImage);
	imshow("output", dst);
	std::cout << "take " << (time1 - time0) / getTickFrequency() << " seconds" << std::endl;
	waitKey(0);
	return 0;
}
