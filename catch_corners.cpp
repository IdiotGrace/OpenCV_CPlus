//
//  catch_corners.cpp
//  testcv
//
//  Created by haowenchao on 3/29/19.
//  Copyright © 2019 haowenchao. All rights reserved.
//

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

void DrawLine(Mat img, Point start, Point end);//画斜线
void DrawPoint(Mat img,Point start, Point end);//画斜点

Mat srcImg;

int main()
{
    srcImg = imread("file/line.jpg");
    if(!srcImg.data){
        cout << "failed to open file" << endl;
        return 0;
    }

    const int nRows = srcImg.rows;
    const int nCols = srcImg.cols;
    cout << "Rows = " << nRows << "; Cols = " << nCols << ";" << endl;
 // DrawLine(srcImg, Point(0, nRows), Point(nCols/2, nRows-nCols/2));
    
    //白点个数
    int nCount = 0;
    //存储白点坐标
    int white[nCols][nRows];
    //将黑白图的白色像素点坐标值记录，输出
    for(int c = 0; c < nCols; c++){
        for(int r = 0; r < nRows; r++){
            if(srcImg.at<uchar>(r, c)==255){
                cout << "[" << c << "," << r << "]";
                white[c][r] = 1;
                nCount++;
            }else{
                white[c][r] = 0;
            }
        }
    }
    cout << "ncount" << nCount << endl;
   /*
    for(int c = 0; c < nCols; c++){
        delete []white[c];
        white = NULL;
    }
    */
    
   
    //纯蓝点个数
//    int nPureCount = 0;
    //存储蓝点坐标
//   int** blue;
    //将图中所有的纯蓝色像素点坐标值输出
    /*
    for(int c = 0; c < nCols/2; c++){
        for(int r = 0; r < nRows; r++){
            if(srcImg.at<Vec3b>(r, c)[0]==255 & srcImg.at<Vec3b>(r, c)[1]==0 & srcImg.at<Vec3b>(r, c)[2]==0){
                cout << "[" << c << "," << r << "]";
          //      blue[c][r] = 1;
                nPureCount++;
            }else{
             //   blue[c][r] = 0;
            }
        }
    }
    cout << "nPureCount" << nPureCount << endl;
    */
    
    //判断蓝点集合中是否有点和白点重合，若有，退出循环，记下坐标。
    
    while(true){
        int delta = 0;
        DrawLine(srcImg, Point(0, nRows+delta), Point(nCols/2, nRows-nCols/2+delta));
        for(int c = 0; c < nCols/2; c++){
            for(int r = 0; r < nRows; r++){
                if(srcImg.at<Vec3b>(r, c)[0]==255 & srcImg.at<Vec3b>(r, c)[1]==0 & srcImg.at<Vec3b>(r, c)[2]==0 & white[r][c]==1){
                    cout << "Find it: [" << c << "," << r << "]";
                    break;
                }else{
                    cout << "Keep finding, delta = " << delta << ";";
                }
            }
        }
        delta++;
    }
    
    imshow("src", srcImg);
    imwrite("file/result.jpg", srcImg);
    waitKey(0);
    return 0;
}


void DrawPoint(Mat img,Point start, Point end)
{
    
}
void DrawLine(Mat img, Point start, Point end)
{
    Scalar color = Scalar(255, 0, 0);
    int thickness = 1;
    int lineType = 8;
    line(img, start, end, color, thickness, LINE_AA);
}
