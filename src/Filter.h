#pragma once
//
//中值滤波---将每一个像素点的灰度值设置为该点邻域窗口内的所有像素点灰度值的中值，
//基于排序统计理论 抑制噪声的非线性信号处理技术，对椒盐噪声有特别功效

//均值滤波
//

class Filter
{
public:
	Filter();

	~Filter();

	void medianfilter(char* pic, char* smoothpic, int width, int height);

public:

private:

};

