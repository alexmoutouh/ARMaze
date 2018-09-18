#include "CameraCV.h"

CameraCV::CameraCV() {
	//this->capture = cv::VideoCapture();
}

CameraCV::~CameraCV() {
}

void CameraCV::openStream() {
	this->capture.open(0);
	if(!this->capture.isOpened()) {
		printf("--(!)Error opening video capture\n");
		return;
	}
}

cv::Mat CameraCV::getFrame() {
	this->capture.read(this->frame);
	return this->frame;
}

void CameraCV::displayStream() {
	cv::namedWindow("Debug CameraCV frame");

	int c = cvWaitKey(10);
	while((char)c != 'q') {
		cv::imshow("Debug CameraCV frame", this->getFrame());
		int c = cvWaitKey(10);
	}
}

byte * CameraCV::getLiveFrame() {
	this->capture.read(this->frame);

	int size = this->frame.total() * this->frame.elemSize();
	byte * bytes = new byte[size];  // you will have to delete[] that later
	std::memcpy(bytes, this->frame.data, size * sizeof(byte));

	return bytes;
}