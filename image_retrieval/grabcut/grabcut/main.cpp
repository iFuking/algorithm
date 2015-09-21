#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
	// Open another image
	Mat image;
	image= cv::imread(argv[1]);

	// define bounding rectangle
	float fac = atof(argv[2]);
	cv::Rect rectangle(image.cols*(1-fac)*0.5, image.rows*(1-fac)*0.5, image.cols*fac, image.rows*fac);

	cv::Mat result; // segmentation result (4 possible values)
	cv::Mat bgModel,fgModel; // the models (internally used)

	// GrabCut segmentation
	cv::grabCut(image,    // input image
            result,   // segmentation result
            rectangle,// rectangle containing foreground
            bgModel,fgModel, // models
            1,        // number of iterations
            cv::GC_INIT_WITH_RECT); // use rectangle
	// Get the pixels marked as likely foreground
	cv::compare(result,cv::GC_PR_FGD,result,cv::CMP_EQ);
	// Generate output image
	cv::Mat foreground(image.size(),CV_8UC3,cv::Scalar(255,255,255));
	
	image.copyTo(foreground,result); // bg pixels not copied
	//imwrite(argv[3],foreground);
	imshow("foo", foreground);
	cvWaitKey(0);
	return 0;
}