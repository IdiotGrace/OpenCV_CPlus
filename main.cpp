//
//  main.cpp
//  testcv
//
//  Created by haowenchao on 3/5/19.
//  Copyright © 2019 haowenchao. All rights reserved.
//

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "image.cpp"
#include "video.cpp"
using namespace std;

int main(int argc, const char * argv[]) {
/*
    Image image_instance;
    image_instance.image_path = "file/pic4.jpg";
    int ret = image_instance.ShowImage(image_instance.image_path);
    return ret;
*/
    
    string video_path = "file/meeting.mp4";
    Video video;
    video.video_path = video_path;
    int result = video.PlayVideo(video.video_path);
    return result;
    
}
