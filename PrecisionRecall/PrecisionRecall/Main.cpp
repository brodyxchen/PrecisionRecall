#include "stdafx.h"


double Recall(Mat& benchmark, Mat& sample, Vec3d blank)
{
	int AC = 0;
	int A = 0;

	Point p;
	for(p.y = 0; p.y < benchmark.rows; p.y++)
	{
		for(p.x = 0; p.x < benchmark.cols; p.x++)
		{
			Vec3d color = benchmark.at<Vec3b>(p);
			if(color == blank) continue;
			AC++;
			Vec3d color2 = sample.at<Vec3b>(p);
			if(color2 != blank) A++;
		}
	}
	return (double)A/AC;
}

double Precision(Mat& benchmark, Mat& sample, Vec3d blank)
{
	int AB = 0;
	int A = 0;

	Point p;
	for(p.y = 0; p.y < benchmark.rows; p.y++)
	{
		for(p.x = 0; p.x < benchmark.cols; p.x++)
		{
			Vec3d color2 = sample.at<Vec3b>(p);
			if(color2 == blank) continue;
			AB++;

			Vec3d color = benchmark.at<Vec3b>(p);
			if(color != blank) A++;
		}
	}
	return (double)A/AB;
}

int main()
{
	string benchmarkFileName = "D://benchmark.png";
	string sampleFileName0 = "D://0.png";
	string sampleFileName1 = "D://1.png";
	string sampleFileName2 = "D://2.png";
	string sampleFileName3 = "D://3.png";


	Mat benchmark = imread(benchmarkFileName);
	Mat sample0 = imread(sampleFileName0);
	Mat sample1 = imread(sampleFileName1);
	Mat sample2 = imread(sampleFileName2);
	Mat sample3 = imread(sampleFileName3);

	Point p;
	p.x = 1; p.y = 1;
	Vec3d blank = benchmark.at<Vec3b>(p);

	double value1 = Recall(benchmark, sample0, blank);
	double value2 = Precision(benchmark, sample0, blank);
	cout<<"Recall0="<<value1<<endl;
	cout<<"Precision="<<value2<<endl;

	value1 = Recall(benchmark, sample1, blank);
	value2 = Precision(benchmark, sample1, blank);
	cout<<"Recall1="<<value1<<endl;
	cout<<"Precision="<<value2<<endl;

	value1 = Recall(benchmark, sample2, blank);
	value2 = Precision(benchmark, sample2, blank);
	cout<<"Recall2="<<value1<<endl;
	cout<<"Precision="<<value2<<endl;

	value1 = Recall(benchmark, sample3, blank);
	value2 = Precision(benchmark, sample3, blank);
	cout<<"Recall3="<<value1<<endl;
	cout<<"Precision="<<value2<<endl;


	system("pause");
	return 0;

}

