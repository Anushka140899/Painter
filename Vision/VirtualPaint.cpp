#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img;
vector<vector<int>> newpoints;
/////////////////  Images  //////////////////////

vector<vector<int>> mycolours = { {124,48,117,143,170,255} //Purple
                                 ,{68,72,156,102,126,255} }; //Green

vector<Scalar> mycolval = { {255,0,255},{0,255,0} }; 

Point getContour(Mat imgDil)
{
	vector<vector<Point>>contours;
	vector<Vec4i>heirarchy;
	findContours(imgDil, contours, heirarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	//drawContours(img, contours, -1, Scalar(255, 0, 255),2);

	vector<vector<Point>>conpoly(contours.size());
	vector<Rect>bound(contours.size());
	Point mypoint(0, 0);
	string object;

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conpoly[i], 0.02 * peri, true);

			cout << conpoly[i].size() << endl;
			bound[i] = boundingRect(conpoly[i]);

			mypoint.x = bound[i].x + bound[i].width / 2;
			mypoint.y = bound[i].y;
			drawContours(img, conpoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, bound[i].tl(), bound[i].br(), Scalar(0, 0, 0), 2);

		}
	}
	return mypoint;
}

vector<vector<int>> findcolour(Mat img)
{
	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	for (int i = 0; i < mycolours.size(); i++)
	{
		Scalar lower(mycolours[i][0], mycolours[i][1], mycolours[i][2]);
		Scalar upper(mycolours[i][3], mycolours[i][4], mycolours[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		//imshow(to_string(i), mask);
		Point mypoint = getContour(mask);

		if (mypoint.x != 0 && mypoint.y != 0)
		{
			newpoints.push_back({ mypoint.x,mypoint.y,i });
		}
	}
	return newpoints;
}

void drawOnCanvas(vector<vector<int>> newpoints, vector<Scalar> mycolval)
{
	for (int i = 0; i < newpoints.size(); i++)
	{
		circle(img, Point(newpoints[i][0],newpoints[i][1]), 10, mycolval[newpoints[i][2]],FILLED);
	}
}

int main() {


	VideoCapture cap(0);

	
	while (true)
	{
		cap.read(img);

		newpoints=findcolour(img);
		drawOnCanvas(newpoints, mycolval);
		imshow("Image", img);
		waitKey(1);
	}
	return 0;

}