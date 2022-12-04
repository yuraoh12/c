#include "opencv2/opencv.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main() {
	Mat img;
	img = imread("dog.bmp");

	if (img.empty())
	{
		cerr << "Image load failed!" << endl;
		return -1;
	}

	namedWindow("Image");
	imshow("image", img);

	waitKey();

	return 0;
}