#include "jpeg_encoder.hpp"
#include <sstream>
#include <string>
#include <iostream>
#include <encoder.hpp>
#include <string.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;
int main(int argv, char * argc[]){
	int loop = 1000, qua= 70;


	std::stringstream ss; ss<<"images/1.bmp";
	//ss << "C:\\Users\\Administrator\\Desktop\\raw2jpegTest\\build\\x64-debug\\run\\images\\1.bmp";
	cv::Mat img = cv::imread(ss.str().c_str(),cv::IMREAD_ANYCOLOR);
	std::uint8_t * buffer;
	if (img.isContinuous()) {
		buffer = img.data;
	}
	else {
		buffer = img.data;
	}
	double time;
	int quality = 70;
	jpeg_encoder * encoder = new opencvEncoder();
	for (int i = 0; i < loop; i++) {
		time = encoder->encode("", buffer, img.rows, img.cols, quality);
		std::cout << time/CLOCKS_PER_SEC << std::endl;
	}
	return 1;
}
