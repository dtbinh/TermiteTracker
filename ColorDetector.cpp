//
//  ColorDetector.cpp
//  TermiteTracker
//
//  Created by Niklas on 10/01/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include "ColorDetector.h"

using namespace cv;
using namespace std;

void HSVDetectionWithSplit();

int ColorDetection(){
    //File location
    string filename = "/Users/Niklas/Developer/TermiteTracker/Media/4.jpg";
    
    //Define matrices
    Mat img = imread(filename);
    Mat contrast_img = constrastImage(img);
    Mat imgThreshRed;
    Mat imgThreshGreen;
    Mat blob;
    
    //Threshold based on color ranges (Blue/Green/Red scalars)
    inRange(contrast_img, Scalar(100,100,250), Scalar(200,200,255), imgThreshRed); //RGB range
    inRange(contrast_img, Scalar(100,250,100), Scalar(200,255,200), imgThreshGreen); //RGB range
    
    //Apply Blur effect to make blobs much more coherent
    GaussianBlur(imgThreshRed, imgThreshRed, Size(3,3), 0);
    GaussianBlur(imgThreshGreen, imgThreshGreen, Size(3,3), 0);
    
    //Set SimpleBlobDetector parameters
    SimpleBlobDetector::Params params;
    params.filterByArea = false;
    params.filterByCircularity = false;
    params.filterByConvexity = false;
    params.filterByInertia = false;
    params.filterByColor = true;
    params.blobColor = 255;
    
    SimpleBlobDetector blobDetector(params);
    blobDetector.create("Blob Detection");
    
    //Vectors to store keypoints (center points for a blob)
    vector<KeyPoint> redKeyPoints;
    vector<KeyPoint> greenKeyPoints;
    
    //Try blob detection for both thresholded colors
    blobDetector.detect(imgThreshRed, redKeyPoints);
    blobDetector.detect(imgThreshGreen, greenKeyPoints);
    
    //Draw resulting keypoints
    drawKeypoints(img, redKeyPoints, blob, CV_RGB(255,255,0), DrawMatchesFlags::DEFAULT);
    drawKeypoints(blob, greenKeyPoints, blob, CV_RGB(249,0,255), DrawMatchesFlags::DEFAULT);
    
    //Show resulting images from program execution
    imshow("Detect Red and Green", blob);
    imshow("Green threshold", imgThreshGreen);
    imshow("Red threshold", imgThreshRed);
    imshow("Contrasted image", contrast_img);
    
    waitKey(0);
    
    return 0;
}