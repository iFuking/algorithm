#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cv.h>
#include <cxcore.h>
#include <highgui.h>
using namespace cv;
using namespace std;

const int dimen = 128;
const int Max = 10100;
const int INF = 0x7fffffff;
double _threshold;
int fvs[Max][dimen], fvd[Max][dimen];
double feas[Max][4], fead[Max][4];

typedef struct 
{
	double sx; double sy;
	double dx; double dy;
}PointPair;
vector<PointPair> pp;

void DrawKeyPoints(Mat &src, Mat &dst, vector<PointPair>& keypoints)
{
	for (int i = 0; i < keypoints.size(); i++)
	{
		CvScalar color = {0, 255, 0};
		circle(src, Point(keypoints[i].sx, keypoints[i].sy), 3, color);
		circle(dst, Point(keypoints[i].dx, keypoints[i].dy), 3, color);
	}
	return;
}

int main(int argc, char *argv[])
{
	FILE *s = NULL, *d = NULL;
	int matches = 0;

	s = fopen(argv[1], "r");
	int fvslines = 0, feaslines = 0; 
	char *token, sen[Max];
	while (!feof(s))
	{	
		fgets(sen, Max, s);
		if (strlen(sen) >= 2*dimen) 
		{
			token = strtok(sen, " ");
			for (int i = 0; token != NULL; i++) 
			{
				fvs[fvslines][i] = atoi(token);
				token = strtok(NULL, " ");	
			}
			fvslines++;
		} else if (strlen(sen) > 4*2) {
			token = strtok(sen, " ");
			for (int i = 0; token != NULL; i++)
			{
				feas[feaslines][i] = atof(token);
				token = strtok(NULL, " ");
			}
			feaslines++;
		}
	}
	fclose(s);


	d = fopen(argv[2], "r");	
	int fvdlines = 0, feadlines = 0;
	while (!feof(d))
	{
		fgets(sen, Max, d);
		if (strlen(sen) >= 2*dimen) 
		{
			token = strtok(sen, " ");
			for (int i = 0; token != NULL; i++) 
			{
				fvd[fvdlines][i] = atoi(token);
				token = strtok(NULL, " ");	
			}
			fvdlines++;
		} else if (strlen(sen) > 4*2) {
			token = strtok(sen, " ");
			for (int i = 0; token != NULL; i++)
			{
				fead[feadlines][i] = atof(token);
				token = strtok(NULL, " ");
			}
			feadlines++;
		}
	}
	fclose(d);

	_threshold = atof(argv[3]);
	int cnt = 0;
	for (int i = 0; i < fvslines; i++)
	{
		double st = INF, nd = INF; int fg;
		for (int j = 0; j < fvdlines; j++)
		{
			double euler = 0;
			for (int k = 0; k < dimen; k++)
				euler += (fvs[i][k]-fvd[j][k])*(fvs[i][k]-fvd[j][k]);
			euler = sqrt(euler);
			if (euler < st) { nd = st; st = euler; fg = j;} 
			else if (euler < nd) nd = euler;
		}
		if (nd != INF && nd/st > _threshold) { 
			PointPair node;
			node.sx = feas[i][1], node.sy = feas[i][0];
			node.dx = fead[fg][1], node.dy = fead[fg][0];
			pp.push_back(node);
			cnt++;
		}
	}
	cout << cnt << endl;

	Mat src = imread(argv[4]);
	Mat dst = imread(argv[5]);
	DrawKeyPoints(src, dst, pp);
	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);

	/*FILE *wr = NULL;
	wr = fopen(argv[4], "a");
	fprintf(wr, "%d\n", cnt);
	fclose(wr);*/
	return 0;
}