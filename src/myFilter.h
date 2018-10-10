#pragma once

#include <opencv2/core.hpp>  
#include <opencv2/highgui.hpp>  

#include<ctime>
using namespace cv;
using namespace std;

//
//中值滤波---将每一个像素点的灰度值设置为该点邻域窗口内的所有像素点灰度值的中值，
//基于排序统计理论 抑制噪声的非线性信号处理技术，对椒盐噪声有特别功效

//均值滤波
//中心点的像素为全部点像素值的平均值。
//缺陷：均值滤波本身存在着固有的缺陷，
//即它不能很好地保护图像细节，在图像去噪的同时也破坏了图像的细节部分，
//从而使图像变得模糊，不能很好地去除噪声点。特别是椒盐噪声
class myFilter
{
public:
	myFilter();

	~myFilter();

	/*
		i - 1, j - 1	i - 1, j	i - 1, j + 1
		i, j - 1	    i, j	    i, j + 1
		i + 1, j - 1	i + 1, j	i + 1, j + 1
		*/
		//n:channal
	void MedianFlter(const Mat &src, Mat &dst);
	//均值滤波
	void AverFiltering(const Mat &src, Mat &dst);
public:
	void salt(cv::Mat& image, int num);//图像椒盐化
private:

};
