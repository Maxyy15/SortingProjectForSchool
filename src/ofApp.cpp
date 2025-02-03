#include "ofApp.h"

vector<int> arr(5);
bool isRandomTrue = false;
bool isBubbleTrue = false;
float duration = 1000;
float startTime;

void bubbleSort(std::vector<int>& arr)
{

}


//--------------------------------------------------------------
void ofApp::setup()
{
	//startTime = ofGetElapsedTimef();
	startTime = ofGetElapsedTimeMillis();

}

//--------------------------------------------------------------
void ofApp::update()
{
	//float elapsed = ofGetElapsedTimef() - startTime;
	//float progress = ofClamp(elapsed / duration, 0.0, 1.0);

	if (isBubbleTrue == true)
	{
		int arrSize = arr.size();
		bool sorted = false;
		if (ofGetElapsedTimeMillis() - startTime >= duration)
		{
			if (!sorted)
			{
				sorted = true;
				for (int i = 0; i < arrSize - 1; i++)
				{
					if (arr[i] > arr[i + 1])
					{
						std::swap(arr[i], arr[i + 1]);
						sorted = false;
					}
				}
			}
			startTime = ofGetElapsedTimeMillis();
			if (sorted)
			{
				isBubbleTrue = false;
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (isRandomTrue == true)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			arr[i] = std::rand() % 100 + 10;
			std::cout << arr[i] << " ";
		}

		isRandomTrue = false;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		ofDrawCircle(100 + (i * 200), 300, arr[i]);
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
	if (key == 'b')
	{
		//bubbleSort(arr);
		isBubbleTrue = true;
	}
	if (key == 'r')
	{
		isRandomTrue = true;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

