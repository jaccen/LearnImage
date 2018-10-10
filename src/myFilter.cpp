#include "myFilter.h"


myFilter::myFilter()
{
}


myFilter::~myFilter()
{
}
/*
把每个像素用周围8个像素做均值操作
平滑图像，降低锐度，但是不能剔除噪声，几乎对降噪没用
*/
void myFilter::MedianFlter(const Mat &src, Mat &dst)
{
	if (!src.data)
	{
		return;
	}
	//

}

void myFilter::AverFiltering(const Mat &src, Mat &dst)
{
	if (!src.data)
	{
		return;
	}
	//
	for (int i = 1; i < src.rows; ++i)
	{
		for (int j = 1; j < src.cols; ++j)
		{
			//边缘不处理
			if ((i - 1) >= 0 && (j - 1) >= 0 && (i + 1) < src.rows && (j + 1) < src.cols)
			{
				for (int m = 0; m < 3; ++m)
				{
					dst.at<Vec3b>(i - 1, j + 1)[m] = (
						src.at<Vec3b>(i, j)[m] +
						src.at<Vec3b>(i - 1, j - 1)[m] +
						src.at<Vec3b>(i - 1, j)[m] +
						src.at<Vec3b>(i, j - 1)[m] +
						src.at<Vec3b>(i - 1, j + 1)[m] +
						src.at<Vec3b>(i + 1, j - 1)[m] +
						src.at<Vec3b>(i + 1, j + 1)[m] +
						src.at<Vec3b>(i, j + 1)[m] +
						src.at<Vec3b>(i + 1, j)[m]
						) / 9;
				}
			}
			else//边缘处理
			{
				dst.at<Vec3b>(i, j)[0] = src.at<Vec3b>(i, j)[0];
				dst.at<Vec3b>(i, j)[1] = src.at<Vec3b>(i, j)[1];
				dst.at<Vec3b>(i, j)[2] = src.at<Vec3b>(i, j)[2];
			}

		}
	}
}

void myFilter::salt(cv::Mat& image, int num)
{
	if (!image.data)
	{
		return;
	}

	int i = 0;
	int j = 0;

	srand(time(nullptr));

	for (int k = 0; k < num; ++k)
	{
		i = rand() % image.rows;
		j = rand() % image.cols;

		image.at<Vec3b>(i, j)[0] = 255;
		image.at<Vec3b>(i, j)[1] = 255;
		image.at<Vec3b>(i, j)[2] = 255;
	}
}
