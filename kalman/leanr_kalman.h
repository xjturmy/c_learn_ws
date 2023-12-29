#ifndef _KALMAN_FILTER_X_
#define _KALMAN_FILTER_X_

#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

class  KalmanFilterX
{
public:
	KalmanFilterX();
	/** @overload
	@param dynamParams Dimensionality of the state.
	@param measureParams Dimensionality of the measurement.
	@param controlParams Dimensionality of the control vector.
	@param type Type of the created matrices that should be CV_32F or CV_64F.
	*/
	KalmanFilterX(int dynamParams, int measureParams, int controlParams = 0, int type = CV_32F);

	/** @brief Re-initializes Kalman filter. The previous content is destroyed.

	@param dynamParams Dimensionality of the state.
	@param measureParams Dimensionality of the measurement.
	@param controlParams Dimensionality of the control vector.
	@param type Type of the created matrices that should be CV_32F or CV_64F.
	 */
	void init(int dynamParams, int measureParams, int controlParams = 0, int type = CV_32F);

	/** @brief Computes a predicted state.

	@param control The optional input control
	 */
	const cv::Mat& predict(const cv::Mat& control = cv::Mat());

	/** @brief Updates the predicted state from the measurement.

	@param measurement The measured system parameters
	 */
	const cv::Mat& correct(const cv::Mat& measurement);

	cv::Mat statePre;           //!< predicted state (x'(k)): x(k)=A*x(k-1)+B*u(k)
	cv::Mat statePost;          //!< corrected state (x(k)): x(k)=x'(k)+K(k)*(z(k)-H*x'(k))
	cv::Mat transitionMatrix;   //!< state transition matrix (A)
	cv::Mat controlMatrix;      //!< control matrix (B) (not used if there is no control)
	cv::Mat measurementMatrix;  //!< measurement matrix (H)
	cv::Mat processNoiseCov;    //!< process noise covariance matrix (Q)
	cv::Mat measurementNoiseCov;//!< measurement noise covariance matrix (R)
	cv::Mat errorCovPre;        //!< priori error estimate covariance matrix (P'(k)): P'(k)=A*P(k-1)*At + Q)*/
	cv::Mat gain;               //!< Kalman gain matrix (K(k)): K(k)=P'(k)*Ht*inv(H*P'(k)*Ht+R)
	cv::Mat errorCovPost;       //!< posteriori error estimate covariance matrix (P(k)): P(k)=(I-K(k)*H)*P'(k)

	// temporary matrices
	cv::Mat temp1;
	cv::Mat temp2;
	cv::Mat temp3;
	cv::Mat temp4;
	cv::Mat temp5;
}; 
#endif
