//
//  jump_video.cpp
//  testcv
//
//  Created by haowenchao on 3/9/19.
//  Copyright © 2019 haowenchao. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;

int g_slider_position = 0;
int g_run = 1, g_dontset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlide(int pos, void *){
    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
    if(!g_dontset){
        g_run = 1;
        g_dontset = 0;
    }
}

int main(int argc, const char * argv[]) {
    cv::namedWindow("Video_jump_example", cv::WINDOW_AUTOSIZE);
    g_cap.open("file/meeting.mp4");
    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
    int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
    int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cout << "Video has " << frames << " frames of dimensions(" << tmpw << ", "<< tmph << ")." << endl;
    
    cv::createTrackbar("Position", "Example2_4", &g_slider_position, frames, onTrackbarSlide);

}


