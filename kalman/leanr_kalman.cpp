#include <stdio.h>
#include <iostream>
#include <vector>
#include "leanr_kalman.h"

// 打印矩阵数据
void printMatrix(const cv::Mat& matrix);

int main(void)
{
	// 1.kalman filter setup
	const int stateNum = 4;                                      // 状态值4×1向量(x,y,△x,△y)
	const int measureNum = 2;                                    // 测量值2×1向量(x,y)	
	KalmanFilterX KFX(stateNum, measureNum, 0);                  // 控制矩阵参数默认为0  控制矩阵B 

	std::vector<cv::Point> measureValue;
	measureValue.emplace_back(cv::Point(1,4));
	measureValue.emplace_back(cv::Point(2,7));
	measureValue.emplace_back(cv::Point(3,10));
	measureValue.emplace_back(cv::Point(4,13));
	measureValue.emplace_back(cv::Point(5,16));
	measureValue.emplace_back(cv::Point(6,19));
	measureValue.emplace_back(cv::Point(7,22));
	measureValue.emplace_back(cv::Point(8,25));
	measureValue.emplace_back(cv::Point(9,28));
	measureValue.emplace_back(cv::Point(10,31));

	cv::Mat_<float> transitionmatrix = (cv::Mat_<float>(4, 4) << 1, 0, 1, 0, 
		                                                         0, 1, 0, 1,
		                                                         0, 0, 1, 0, 
		                                                         0, 0, 0, 1);

	KFX.transitionMatrix = transitionmatrix;                     // 转移矩阵 A
	setIdentity(KFX.measurementMatrix);                          // 测量矩阵H
	setIdentity(KFX.processNoiseCov, cv::Scalar::all(1e-5));     // 系统噪声方差矩阵Q
	setIdentity(KFX.measurementNoiseCov, cv::Scalar::all(1e-1)); // 测量噪声方差矩阵R
	setIdentity(KFX.errorCovPost, cv::Scalar::all(1));           // 后验错误估计协方差矩阵P
	
    // 初始状态值x(0)
	// setIdentity(KFX.statePost, cv::Scalar::all(1)); 

	// 初始测量值x'(0)，因为后面要更新这个值，所以必须先定义
	cv::Mat measurement = cv::Mat::ones(measureNum, 1, CV_32F);   

	for(int i=0; i < measureValue.size(); ++i)
	{
		// 2.kalman prediction
		cv::Mat prediction = KFX.predict(); // 输出是下一时刻的状态值KFX.statePost(k+1)
		cv::Point predict_pt = cv::Point(prediction.at<float>(0), prediction.at<float>(1));   // 预测值(x',y')

		// 3.update measurement
		measurement.at<float>(0) = (float)measureValue[i].x;
		measurement.at<float>(1) = (float)measureValue[i].y;

		// 4.update
		KFX.correct(measurement);  // 经过KFX.correct()之后，最终的结果应该是KFX.statePost

		//printMatrix(KFX.transitionMatrix);    // A
		//std::cout << "---A---" << std::endl;
		//printMatrix(KFX.measurementMatrix);   // H
		//std::cout << "---H---" << std::endl;  
		//printMatrix(KFX.processNoiseCov);     // Q
		//std::cout << "---Q---" << std::endl;
		//printMatrix(KFX.measurementNoiseCov); // R
		//std::cout << "---R---" << std::endl;
		//printMatrix(KFX.gain);                // K
		//std::cout << "---K---" << std::endl;
		//printMatrix(KFX.errorCovPre);         // errorCovPre
		//std::cout << "---errorCovPre---" << std::endl;
		//printMatrix(KFX.errorCovPost);        // errorCovPost
		//std::cout << "---errorCovPost---" << std::endl;

		std::cout << "predict (x, y): " << predict_pt.x << " , " << predict_pt.y << std::endl;
		std::cout << "measureValue (x, y): " << measureValue[i].x << " , " << measureValue[i].y << std::endl;
		std::cout << "KFX.statePost (x, y): " << KFX.statePost.at<float>(0) << " , " << KFX.statePost.at<float>(1) << std::endl;
	}

	return 0;
}

void printMatrix(const cv::Mat& matrix)
{
	std::cout << "--------------beigin---------------" << std::endl;

	for (size_t i = 0; i < matrix.rows; ++i)
	{
		for (size_t j = 0; j < matrix.cols; ++j)
		{
			std::cout << " " << matrix.at<float>(i, j);
		}
		std::cout << std::endl;
	}

	std::cout << "--------------end----------------" << std::endl;
}
