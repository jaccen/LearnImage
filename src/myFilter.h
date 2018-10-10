#pragma once

#include <opencv2/core.hpp>  
#include <opencv2/highgui.hpp>  

#include<ctime>
using namespace cv;
using namespace std;

//
//��ֵ�˲�---��ÿһ�����ص�ĻҶ�ֵ����Ϊ�õ����򴰿��ڵ��������ص�Ҷ�ֵ����ֵ��
//��������ͳ������ ���������ķ������źŴ��������Խ����������ر�Ч

//��ֵ�˲�
//���ĵ������Ϊȫ��������ֵ��ƽ��ֵ��
//ȱ�ݣ���ֵ�˲���������Ź��е�ȱ�ݣ�
//�������ܺܺõر���ͼ��ϸ�ڣ���ͼ��ȥ���ͬʱҲ�ƻ���ͼ���ϸ�ڲ��֣�
//�Ӷ�ʹͼ����ģ�������ܺܺõ�ȥ�������㡣�ر��ǽ�������
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
	//��ֵ�˲�
	void AverFiltering(const Mat &src, Mat &dst);
public:
	void salt(cv::Mat& image, int num);//ͼ���λ�
private:

};
