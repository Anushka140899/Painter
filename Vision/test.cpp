#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


/////////////////  Images  //////////////////////

int main() {


	VideoCapture cap(0);

	Mat img;
		while (true)
		{
			if (!cap.read(img))
			{
				break;
			}
			imshow("Image", img);
			waitKey(20);
		}
    return 0;

}

//int main()
//{
	//string path = "Resources/test_video.mp4";
//	VideoCapture cap("Vision / Resources / test_video.mp4");

	//if (!cap.isOpened())  // check if we succeeded
		//return -1;

	//namedWindow("Images", 1);
	//while (true)
	//{
		//Mat img;

		//cap >> img;
		//imshow("Images", img);

		//if (waitKey(30) >=0 )
		//{
			//break;
		//}
	//}
	//return 0;
