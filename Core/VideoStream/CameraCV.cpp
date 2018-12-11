#include "CameraCV.h"

CameraCV::CameraCV() {
	this->capture = cv::VideoCapture();
}

CameraCV::~CameraCV() {
}

cv::VideoCapture CameraCV::getVid() {
	return this->capture;
}

void CameraCV::openStream(int inputId /* = 0 */) {
	this->capture.open(inputId);
	if(!this->capture.isOpened()) {
		printf("--(!)Error opening video capture\n");
		return;
	}
}

void CameraCV::closeStream() {
	if(this->capture.isOpened()) {
		this->capture.release();
	}

	cvDestroyAllWindows();
}

bool CameraCV::readFrame() {
	return this->capture.read(this->frame);
}

cv::Mat CameraCV::getFrame() {
	return this->frame;
}

int CameraCV::getWidth() {
	return this->frame.cols;
}

int CameraCV::getHeigth() {
	return this->frame.rows;
}

void CameraCV::displayStream() {
	cv::namedWindow("Debug CameraCV Window");

	while(true) {
		this->readFrame();
		cv::imshow("Debug CameraCV Window", this->getFrame());
		int c = cvWaitKey(10);
		if(c >= 0) {
			this->closeStream();
			break;
		}
	}
}

uchar * CameraCV::getLiveFrame(int * sizeofMat) {
	this->capture.read(this->frame);
	cv::cvtColor(this->frame, this->frame, CV_BGR2BGRA, 4);
	*sizeofMat = this->frame.rows * this->frame.cols * 4; //this->frame.total() * this->frame.elemSize();

	return this->frame.data;
}

