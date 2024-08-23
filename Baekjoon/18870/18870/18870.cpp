#include <iostream>
using namespace std;

struct Node {
	int coordinate;
	int sortedIdx;
};

Node** tempCoordinates;

void merge(Node** copiedCoordinates, int leftIndex, int midIndex, int rightIndex) {
	int i = leftIndex;
	int j = midIndex + 1;
	int k = leftIndex;

	while (i <= midIndex && j <= rightIndex)
	{
		if (copiedCoordinates[i]->coordinate < copiedCoordinates[j]->coordinate) {
			tempCoordinates[k++] = copiedCoordinates[i++];
		}
		else {
			tempCoordinates[k++] = copiedCoordinates[j++];
		}
	}

	int tmp = i > midIndex ? j : i;

	while (k <= rightIndex) {
		tempCoordinates[k++] = copiedCoordinates[tmp++];
	}

	// 재입력
	for (int i = leftIndex; i <= rightIndex; i++) {
		copiedCoordinates[i] = tempCoordinates[i];
	}
}

void mergeSort(Node** copiedCoordinates, int leftIndex, int rightIndex) {
	int midIndex;

	if (leftIndex < rightIndex) {
		midIndex = (leftIndex + rightIndex) / 2;
		mergeSort(copiedCoordinates, leftIndex, midIndex);
		mergeSort(copiedCoordinates, midIndex + 1, rightIndex);
		merge(copiedCoordinates, leftIndex, midIndex, rightIndex);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Node** coordinates;
	Node** copiedCoordinates;

	int numOfCoordinates;
	cin >> numOfCoordinates;
	coordinates = new Node*[numOfCoordinates];
	copiedCoordinates = new Node*[numOfCoordinates];
	tempCoordinates = new Node* [numOfCoordinates];

	int coordinate;
	for (int i = 0; i < numOfCoordinates; i++) {
		cin >> coordinate;
		Node* node = new Node{coordinate, 0};
		coordinates[i] = node;
		copiedCoordinates[i] = node;
		tempCoordinates[i] = new Node{ 0, 0 };
	}

	mergeSort(copiedCoordinates, 0, numOfCoordinates - 1);

	int previousIdx = -1;
	int previousValue = 0;
	for (int i = 0; i < numOfCoordinates; i++) {
		if (previousValue != copiedCoordinates[i]->coordinate) {
			previousValue = copiedCoordinates[i]->coordinate;
			copiedCoordinates[i]->sortedIdx = ++previousIdx;
		}
		else {
			copiedCoordinates[i]->sortedIdx = previousIdx;
		}
	};

	for (int i = 0; i < numOfCoordinates; i++) {
		cout << coordinates[i]->sortedIdx << " ";
	};

	for (int i = 0; i < numOfCoordinates; i++) {
		delete coordinates[i];
	}
	delete[] coordinates;
	delete[] copiedCoordinates;
	delete[] tempCoordinates;
	return 0;
}
