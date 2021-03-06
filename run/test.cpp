#include "jpeg_encoder.hpp"
#include "opencv2/core/hal/interface.h"
#include "opencv2/core/utility.hpp"
#include <ctime>
#include <encoder.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <string>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>

void RunTest(jpeg_encoder *encoder, char *encoderName, int testmode);
double RunTestOnImage(jpeg_encoder *encoder, int img_num, int qua, std::uint8_t* buffer, int h, int w);
double RunTestOnImages(jpeg_encoder *encoder, int qul, std::uint8_t* buffer, int h, int w);

int main(int argc, char *argv[]){
	// read
	/*
	if(argc != 4){
		std::cout << "argc error" << std::endl;
		return 1;
	}
	//bool hal = strcmp(argv[4],"yes")==0? true:false;

	char * encoderName = argv[1];
	int test = strcmp(argv[2],"image")==0?1:2;
	int loop;
	std::string s(argv[3]);
	std::stringstream ss;
	ss<<s;
	ss>>loop;

	int index = 0;

	if(strcmp(encoderName, "opencv") == 0){
		index = 0;
		//cv::setUseOptimized(hal);
	}
	else if(strcmp(encoderName, "turbo") == 0) 
		index = 1;
	else if(strcmp(encoderName, "libjpeg") == 0)
		index = 2;
*/
	int index = 0;
	int loop = 1;
	char * encoderName = "opencv_acc";
	int test = 2;
	std::uint8_t * buffer;
	std::vector<jpeg_encoder *> encoders;
	encoders.push_back(new opencvEncoder());
	encoders.push_back(new TurboEncoder());
	encoders.push_back(new libjpegEncoder());
	for(int i =0 ; i <loop ;i++)
		RunTest(encoders[index], encoderName, test);
	return 1;
}


void RunTest(jpeg_encoder* encoder, char *encoderName, int testmode){
	if(testmode == 1){
		clock_t start, end;
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
		std::string path = std::string(encoderName) + "_image";
		std::ofstream ofs(path, std::ios::out|std::ios::binary|std::ios::trunc);
		int img_num = 12;
		double second;
		for(int i = 1 ; i < img_num ; ++i){
			second = encoder->encode("not", buffer, img.rows, img.cols, 70);
			ofs<< second / CLOCKS_PER_SEC << std::endl;
		}
		for(int i = 1 ; i < img_num ; ++i){
			second = encoder->encode("not", buffer, img.rows, img.cols, 60);
			ofs<< second / CLOCKS_PER_SEC << std::endl;
		}
		for(int i = 1 ; i < img_num ; ++i){
			second = encoder->encode("not", buffer, img.rows, img.cols, 10);
			ofs<< second / CLOCKS_PER_SEC << std::endl;
		}
		ofs.close();
	}
	else{
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
		std::string path = std::string(encoderName) + "_quality";
		std::ofstream ofs(path, std::ios::out | std::ios::binary |std::ios::trunc);
		for(int qua = 10; qua<=90 ; qua = qua + 1){
			time = RunTestOnImages(encoder, qua, buffer, img.rows, img.cols);
			ofs<<time<<",";
		}
	}

}

double RunTestOnImage(jpeg_encoder *encoder, int img_num, int qua, uchar* buffer, int hight, int width){
	double time = encoder->encode("temp.jpg", buffer, hight, width, qua);
	return time/CLOCKS_PER_SEC;
}

double RunTestOnImages(jpeg_encoder *encoder, int qul, uchar* buffer , int height, int width){
	
	int img_num = 10;
	double second = 0;
	for(int i = 0 ; i < img_num ; ++i){
		second = second + RunTestOnImage(encoder, i, qul, buffer, height, width);
	}
	return second/10;
}
