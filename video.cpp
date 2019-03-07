//
//  video.cpp
//  testcv
//
//  Created by haowenchao on 3/6/19.
//  Copyright © 2019 haowenchao. All rights reserved.
//

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;

class Video
{
public:
    string video_path;
    
    /*
     Play video. Press key>0 to exit
     */
    int PlayVideo(string video_path){
        cv::namedWindow("Example_Video", cv::WINDOW_AUTOSIZE);
        cv::VideoCapture cap;
        cap.open(video_path);
        cv::Mat frame;
        for(;;){
            cap >> frame;
            if(frame.empty())
                break;
            cv::imshow("Example_Video", frame);
            if(cv::waitKey(33) >= 0)
                break;
        }
        return 0;
    }
    
    void onTrackbarSlide(int pos, void *){
        
    }
    int JumpVideo(string video_path){
        int g_slider_position = 0;
        int g_run = 1, g_dontset = 0;
        cv::VideoCapture g_cap;
        
    }
    
};

