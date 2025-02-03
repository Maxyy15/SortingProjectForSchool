#include "ofApp.h"

vector<int> arr(5);

bool isRandomTrue = false;
bool isBubbleTrue = false;
bool isInsertionTrue = false;
bool isMergeTrue = false;
bool isQuickTrue = false;

float duration = 1000;
float startTime;

//This was a combination of me and ChatGPT, but I did most of the work
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

//The merge sort was adapted from this youtube video, but it's basically a 1 to 1 copy
//I want to eventually remake this in my own unique code
//https://www.youtube.com/watch?v=3j0SWDX4AtU
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

//The quick sort was adapted from this youtube video
//I want to eventually remake this in my own unique code
//https://www.youtube.com/watch?v=Vtckgz38QHs
int Partition(vector<int>& arr, int startIndex, int endIndex)
{
	int pivot = arr[endIndex];
	int i = startIndex - 1;

	for (int j = startIndex; j <= endIndex - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	i++;
	int temp = arr[i];
	arr[i] = arr[endIndex];
	arr[endIndex] = temp;

	return i;
}
void QuickSorting(vector<int>& arr, int startIndex, int endIndex)
{
	if (endIndex <= startIndex) return;

	int pivot = Partition(arr, startIndex, endIndex);
	QuickSorting(arr, startIndex, pivot - 1);
	QuickSorting(arr, pivot + 1, endIndex);

	isQuickTrue = false;
}

//The insertion sort was adapted from this youtube video
//I want to eventually remake this in my own unique code
//https://www.youtube.com/watch?v=8mJ-OhcfpYg
void InsertionSorting(vector<int>& arr)
{
	for (int i = 1; i < arr.size(); i++)
	{
		int temp = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = temp;
	}
	isInsertionTrue = false;
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

	if (isInsertionTrue == true)
	{
		InsertionSorting(arr);
	}

	if (isQuickTrue == true)
	{
		QuickSorting(arr, 0, arr.size() - 1);
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

