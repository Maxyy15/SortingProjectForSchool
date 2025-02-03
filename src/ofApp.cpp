#include "ofApp.h"

vector<int> arr(5);

bool isRandomTrue = false;
bool isBubbleTrue = false;
bool isInsertionTrue = false;
bool isMergeTrue = false;
bool isQuickTrue = false;

float duration = 1000;
float startTime;


void BubbleSorting(vector<int>& arr)
{
	int length = arr.size();
	bool sorted = false;
	if (ofGetElapsedTimeMillis() - startTime >= duration)
	{
		if (!sorted)
		{
			sorted = true;
			for (int i = 0; i < length - 1; i++)
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

void Merge(vector<int>& leftArr, vector<int>& rightArr, vector<int>& arr)
{
	int leftSize = arr.size() / 2;
	int rightSize = arr.size() - leftSize;
	int i = 0, l = 0, r = 0;

	while (l < leftSize && r < rightSize)
	{
		if (leftArr[l] < rightArr[r])
		{
			arr[i] = leftArr[l];
			i++;
			l++;
		}
		else
		{
			arr[i] = rightArr[r];
			i++;
			r++;
		}
	}
	while (l < leftSize)
	{
		arr[i] = leftArr[l];
		i++;
		l++;
	}
	while (r < rightSize)
	{
		arr[i] = rightArr[r];
		i++;
		r++;
	}
}
void MergeSorting(vector<int>& arr)
{
	int length = arr.size();
	if (length <= 1) return;

	int middle = length / 2;
	vector<int> leftArr(middle);
	vector<int> rightArr(length - middle);

	int i = 0; //left array
	int j = 0; //right array

	for (; i < length; i++)
	{
		if (i < middle)
		{
			leftArr[i] = arr[i];
		}
		else
		{
			rightArr[j] = arr[i];
			j++;
		}
	}
	MergeSorting(leftArr);
	MergeSorting(rightArr);
	Merge(leftArr, rightArr, arr);

	isMergeTrue = false;
}


//--------------------------------------------------------------
void ofApp::setup()
{
	startTime = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void ofApp::update()
{
	if (isBubbleTrue == true)
	{
		BubbleSorting(arr);
	}

	if (isMergeTrue == true)
	{
		MergeSorting(arr);
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
	if (key == 'r')
	{
		isRandomTrue = true;
	}

	if (key == 'b')
	{
		isBubbleTrue = true;
	}

	if (key == 'i')
	{
		isInsertionTrue = true;
	}

	if (key == 'm')
	{
		isMergeTrue = true;
	}

	if (key == 'q')
	{
		isQuickTrue = true;
	}

	if (key == 'c')
	{
		system("cls");
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

