#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(0, 0, 0), FILLED);
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255), 3);
	putText(img, "Anushka Shukla", Point(155, 262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);
	imshow("Image", img);
	waitKey(0);
}