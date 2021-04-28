#include "opencvEncoder.hpp"
#include "opencv2/core/hal/interface.h"
#include "opencv2/core/mat.hpp"
#include "opencv2/core/utility.hpp"
#include <bits/types/clock_t.h>
#include <ctime>
#include <jpeglib.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <vector>


double opencvEncoder::encode(char *strImageName, std::uint8_t *image_buffer, int image_height, int image_width, int quality){
	
	cv::setUseOptimized(true);
	cv::Mat img(cv::Size(image_width, image_height), CV_8UC3, image_buffer);
	std::vector<int> compression_params;
	compression_params.push_back(cv::IMWRITE_JPEG_QUALITY);
	compression_params.push_back(quality);
	clock_t start,end;
	start=clock();
	cv::imwrite(strImageName, img, compression_params);
	end = clock();
	return (double)(end - start);
}
