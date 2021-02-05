#include <bits/stdc++.h>
#include <opencv2/opencv.hpp>


cv::RNG rng(12345);
cv::Point pos;
int width = 0, height = width;
bool isDraw = false;

int maxWidth = 800, maxHeight = 600;

void drawRectangle(int event, int x, int y, int flags, void *param) {
	cv::Mat &img = *(cv::Mat *) param;

	switch (event) {
		case cv::EVENT_MOUSEMOVE:
			if (isDraw) {
				width = x - pos.x;
				height = y - pos.y;
			}
			break;
		case cv::EVENT_LBUTTONDOWN:
			isDraw = true;
			pos.x = x;
			pos.y = y;
			break;
		case cv::EVENT_LBUTTONUP:
			isDraw = false;
			cv::rectangle(img, pos, cv::Point(pos.x + width, pos.y + height),
			              cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)));
			width = height = 0;
			break;
	}
}

/**
 * @brief draw rectangle via mouse
 */
void onMouse() {
	std::string windowname = "draw rectangle";

	cv::Mat img(800, 600, CV_8UC3);
	cv::namedWindow(windowname);
	cv::setMouseCallback(windowname, drawRectangle, &img);
	img = cv::Scalar::all(0);
	while (true) {
		cv::Mat dst = img.clone();
		if (isDraw)
			cv::rectangle(dst, pos, cv::Point(pos.x + width, pos.y + height),
			              cv::Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255)));
		cv::imshow(windowname, dst);
		if (cv::waitKey(10) == 27) {
			break;
		}
	}
}

int main(int argc, char **argv) {
	cv::Mat img = cv::imread("/home/sasuke/Pictures/img4.jpg");
	std::string srcName("src"), outName("out");
	cv::namedWindow(srcName, cv::WINDOW_NORMAL);
	cv::ellipse(img, cv::Point(400, 400), cv::Size(300, 100), 30, 90, 360, cv::Scalar(123, 123, 123));
	cv::circle(img, cv::Point(400, 400), 100, cv::Scalar(22, 222, 22));

	cv::Point **points = new cv::Point *(new cv::Point[3]{cv::Point(12, 23), cv::Point(222, 22), cv::Point(55, 555)});


	cv::fillPoly(img, (const cv::Point **) points, new int[1]{3}, 1, cv::Scalar(222, 222, 22));
	cv::imshow(srcName, img);
	cv::waitKey(0);
	return 0;
}