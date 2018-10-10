#include <iostream>  
#include <opencv2/core.hpp>  
#include <opencv2/highgui.hpp>  
#include "../src/myFilter.h"
using namespace cv;
//
void ImgOperate(IplImage* image)
{
	cvNamedWindow("Image-in", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Image_access", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Image-Out", CV_WINDOW_AUTOSIZE);
	cvShowImage("Image-in", image);

	IplImage* pImge = nullptr;
	
}
int main()
{
	myFilter filter;
	Mat image = imread("timg.jpg");
	namedWindow("sample");
	Mat Salt_Image;
	image.copyTo(Salt_Image);
	filter.salt(Salt_Image, 3000);
	Mat image1(image.size(), image.type());
	Mat image2;	
	imshow("加噪声图像", Salt_Image);
	filter.AverFiltering(Salt_Image, image1);
	//blur(Salt_Image, image2, Size(3, 3));//openCV库自带的均值滤波函数
	imshow("原图", image);	
	imshow("自定义均值滤波", image1);	
	//imshow("openCV自带的均值滤波", image2);	
	waitKey();


	return 0;
}
