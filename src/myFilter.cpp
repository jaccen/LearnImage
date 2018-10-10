#include "myFilter.h"


myFilter::myFilter()
{
}


myFilter::~myFilter()
{
}
/*
��ÿ����������Χ8����������ֵ����
ƽ��ͼ�񣬽�����ȣ����ǲ����޳������������Խ���û��
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
			//��Ե������
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
			else//��Ե����
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
