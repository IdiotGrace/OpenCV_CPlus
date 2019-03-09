//
//  image.cpp
//  testcv
//
//  Created by haowenchao on 3/6/19.
//  Copyright © 2019 haowenchao. All rights reserved.
//

#include <opencv2/opencv.hpp>
using namespace std;

int ShowImage(string image_path)
{
    cv::Mat img = cv::imread(image_path);
    if(img.empty())
        return -1;
    cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
    cv::imshow("Example1", img);
    cv::waitKey(0);
    cv::destroyWindow("Example1");
    return 0;
}

/*
int main(int argc, const char * argv[]) {
    string image_path = "file/pic4.jpg";
    int return_value = ShowImage(image_path);
    return return_value;
}
*/


    





