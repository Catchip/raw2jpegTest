#include "jpeg_encoder.hpp"
#include <sstream>
#include <string>
#include <encoder.hpp>
#include <string.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>

using namespace std;
using namespace cv;
int main(int argv, char * argc[]){
	int loop,qua;
	stringstream ss;
	string s(argc[1]);
	ss<<s;
	ss>>loop;
	std::cout << loop << std::endl;
	ss.clear();

	ss<<argc[2];
	ss>>qua;
	ss.clear();

	jpeg_encoder * encoder;
	if(strcmp(argc[3], "opencv")==0)
		encoder = new opencvEncoder();
	else
		encoder = new TurboEncoder();
	Mat img = imread("images/1.jpg");	
	uint8_t * buffer = img.data;
	for(int i = 0 ; i< loop ; ++i){
		encoder->encode("tmp.jpg", buffer, img.rows, img.cols, qua);
	}
	return 1;
}
