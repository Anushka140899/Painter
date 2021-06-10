#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgresize,imgCrop;

	resize(img, imgresize, Size(640, 480));
	Rect roi(200, 100, 300, 300);
	imgCrop = img(roi);

	imshow("Images", img);
	imshow("Image Crop", imgCrop);
	waitKey(0);
}