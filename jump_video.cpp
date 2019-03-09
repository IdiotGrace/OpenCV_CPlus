//
//  jump_video.cpp
//  testcv
//
//  Created by haowenchao on 3/9/19.
//  Copyright © 2019 haowenchao. All rights reserved.
//

#include <stdio.h>
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
   

}


