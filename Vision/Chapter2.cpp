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
	Mat imgGray,imgBlur,imgcanny,imgdil,imgero;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);      //Change colour to gray
	GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgcanny, 50, 50);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2));
	dilate(imgcanny, imgdil, kernel);
	erode(imgdil, imgero, kernel);

	imshow("Images", img);
	imshow("Image2", imgGray);
	imshow("Image3", imgBlur);
	imshow("Image4", imgcanny);
	imshow("Image5", imgdil);
	imshow("Image6", imgero);
	waitKey(0);
}