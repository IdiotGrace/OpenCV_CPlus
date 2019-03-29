//
//  detect_corners.cpp
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
Mat MoraveCorners(Mat srcImage, int kSize, int threshold)
{
    Mat resMorMat = srcImage.clone();
    int r = kSize/2; //选定窗口的边界限定
    const int nRows = srcImage.rows;
    const int nCols = srcImage.cols;
    cout << "Rows = " << nRows << "; Cols = " << nCols << ";" << endl;
    int nCount = 0;
    CvPoint *pPoint = new CvPoint[nRows*nCols];
    //遍历图像
    for(int i = r; i < srcImage.rows-r ; i++){
        for(int j = r; j < srcImage.cols-r; j++){
            int wV1, wV2, wV3, wV4;
            wV1 = wV2 = wV3 = wV4 = 0;//初始化
            //计算水平方向窗口内的兴趣值
            for(int k = -r; k < r; k++){
                wV1 += (srcImage.at<uchar>(i, j + k) - srcImage.at<uchar>(i, j + k + 1))* (srcImage.at<uchar>(i, j + k) - srcImage.at<uchar>(i, j + k + 1));
            }
            
            //计算垂直方向窗口内的兴趣值
            for(int k = -r; k < r; k++){
                wV2 += (srcImage.at<uchar>(i + k, j) - srcImage.at<uchar>(i + k + 1, j))* (srcImage.at<uchar>(i + k, j) - srcImage.at<uchar>(i + k + 1, j));
            }
            
            //计算45度方向窗口内的兴趣值
            for(int k = -r; k < r; k++){
                wV3 += (srcImage.at<uchar>(i + k, j + k) - srcImage.at<uchar>(i + k + 1, j + k + 1))* (srcImage.at<uchar>(i + k, j + k) - srcImage.at<uchar>(i + k + 1, j + k + 1));
            }
            
            //计算135度方向窗口内的兴趣值
            for(int k = -r; k < r; k++){
                wV4 += (srcImage.at<uchar>(i + k, j - k) - srcImage.at<uchar>(i + k + 1, j - k - 1))* (srcImage.at<uchar>(i + k, j + k) - srcImage.at<uchar>(i + k + 1, j - k - 1));
            }
            
            //取四个方向下的最小值作为最终兴趣值
            int value = min(min(wV1, wV2), min(wV3, wV4));
            //若兴趣值大于阈值，则将该点[窗口中心点]的坐标存入
            if (value > threshold){
                pPoint[nCount++] = cvPoint(j, i);
            }
        }
    }
    //绘制兴趣值
    for(int i = 0; i < nCount; i++){
        circle(resMorMat, pPoint[i], 5, Scalar(0, 0, 255));
    }
    return resMorMat;
}
/*
int main()
{
    Mat srcImg = imread("file/line.jpg");
    if(!srcImg.data){
        cout << "failed to open file" << endl;
        return 0;
    }
    Mat srcGray;
    cvtColor(srcImg, srcGray, CV_BGR2GRAY);
    Mat result = MoraveCorners(srcGray, 10, 500);
    imshow("src", srcImg);
    imshow("result", result);
    imwrite("file/result.jpg", result);
    waitKey(0);
    return 0;
}
 */

