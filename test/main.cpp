#include <iostream>  
#include <opencv2/core.hpp>  
#include <opencv2/highgui.hpp>  

using namespace cv;

//

int main()
{
	Mat img = imread("timg.jpg");
	namedWindow("sample");
	imshow("sample", img);
	waitKey(0);

	return 0;
}
