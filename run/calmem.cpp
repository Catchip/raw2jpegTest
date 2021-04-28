#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <sstream>
#include <iostream>
using namespace cv;
using namespace std;
int main(){

	int count = 0;
	stringstream ss;
	for(int i =1 ; i < 60 ; ++i){
		ss.clear();
		ss<<"images/"<<i<<".jpg";
		Mat img = imread(ss.str());	
		count = count + img.cols*img.rows*img.channels();
	}
	std::cout << count << std::endl;
	return 0;
}
