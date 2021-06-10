#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

float w = 250, h = 250;
Mat matrix, imgwarp;

int main()
{
	string path = "Resources/cards.jpg";
	Mat img = imread(path);
	Point2f src[4] = { {777,107},{1016,83},{845,358},{1115,331} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgwarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image",img);
	imshow("Image warp", imgwarp);
	waitKey(0);
}