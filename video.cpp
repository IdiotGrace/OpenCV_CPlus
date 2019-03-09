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
    
int main(int argc, const char * argv[]) {
    string video_path = "file/meeting.mp4";
    int return_value = PlayVideo(video_path);
    return return_value;
}
