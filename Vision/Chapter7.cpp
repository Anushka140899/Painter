#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;



void getContour(Mat imgDil,Mat img)
{
	vector<vector<Point>>contours;
	vector<Vec4i>heirarchy;
	findContours(imgDil, contours, heirarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	//drawContours(img, contours, -1, Scalar(255, 0, 255),2);

	vector<vector<Point>>conpoly(contours.size());
	vector<Rect>bound(contours.size());
	string object;
	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conpoly[i],0.02*peri,true);
			
			cout << conpoly[i].size() << endl;
			bound[i] = boundingRect(conpoly[i]);
			//rectangle(img, bound[i].tl(), bound[i].br(), Scalar(0, 0, 0), 2);

			int objcor = (int)conpoly[i].size();

			if (objcor == 3) { object = "Triangle"; }
			else if (objcor == 4) {

				float aspratio = (float)bound[i].width / (float)bound[i].height;
				if (aspratio > 0.95 && aspratio < 1.05)
				{
					object = "Square";
				}
				else { object = "Rectangle"; }
			}
			else if (objcor > 4) { object = "Circle"; }

			drawContours(img, conpoly, i, Scalar(255, 0, 255), 2);
			putText(img, object, { bound[i].x,bound[i].y - 5 }, FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 0, 0), 1);

		}
	}
}

int main()

{
	Mat imgGray, imgBlur, imgCanny, imgDil;
	string path = "Resources/shapes.png";
	Mat img = imread(path);

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
	Canny(imgBlur, imgCanny, 25, 75);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);

	getContour(imgDil, img);

	imshow("Image", img);
	/*imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilate", imgDil);*/
	

	waitKey(0);

}