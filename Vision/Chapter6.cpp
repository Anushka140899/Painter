#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat imghsv, mask;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 250, vmax = 255;

int main()
{
	string path = "Resources/lambo.png";
	Mat img = imread(path);
	
	cvtColor(img, imghsv, COLOR_BGR2HSV);

	/*namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue min", "Trackbars", &hmin, 179);
	createTrackbar("Hue max", "Trackbars", &hmax, 179);
	createTrackbar("Sat min", "Trackbars", &smin, 255);
	createTrackbar("Sat max", "Trackbars", &smax, 255);
	createTrackbar("Val min", "Trackbars", &vmin, 255);
	createTrackbar("Val max", "Trackbars", &vmax, 255);*/
	
	
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imghsv, lower, upper, mask);

		imshow("Image", img);
		imshow("Image hsv", imghsv);
		imshow("Image mask", mask);

		waitKey(0);
	
}