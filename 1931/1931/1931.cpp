#include <iostream>
#include <vector>
using namespace std;
/*
int partition(vector<pair<int, int>>& meetings, int leftIndex, int rightIndex) {
	int pivot = leftIndex;
	int low = leftIndex + 1;
	int high = rightIndex;

	while (low <= high) {
		while (low <= rightIndex && 
			    (meetings[low].second < meetings[pivot].second || 
			    (meetings[low].second == meetings[pivot].second && meetings[low].first < meetings[pivot].first))) {
			++low;
		}

		while (high > leftIndex && 
			   (meetings[high].second > meetings[pivot].second ||
			   (meetings[high].second == meetings[pivot].second && meetings[high].first > meetings[pivot].first))) {
			--high;
		}

		if (low < high) {
			swap(meetings[low], meetings[high]);
		}
	}

	// 교차하였을 경우
	swap(meetings[pivot], meetings[high]);
	return high;
}

// 시작 시간을 기준으로 정렬한다.
void quickSort(vector<pair<int, int>>& meetings, int leftIndex, int rightIndex) {
	if (leftIndex > rightIndex)
		return;

	int pivot = partition(meetings, leftIndex, rightIndex);

	quickSort(meetings, leftIndex, pivot - 1);
	quickSort(meetings, pivot + 1, rightIndex);
}
*/

pair<int, int>* sortedMeetings;

void merge(vector<pair<int, int>>& meetings, int leftIndex, int midIndex, int rightIndex) {
	int i = leftIndex;
	int j = midIndex + 1;
	int k = leftIndex;

	while (i <= midIndex && j <= rightIndex)
	{
		if (meetings[i].second < meetings[j].second) {
			sortedMeetings[k++] = meetings[i++];
		}
		// 회의 종료 시간이 같을 경우 시작 시간 비교
		else if (meetings[i].second == meetings[j].second) {
			if (meetings[i].first <= meetings[j].first) {
				sortedMeetings[k++] = meetings[i++];
			}
			else {
				sortedMeetings[k++] = meetings[j++];
			}
		}
		else {
			sortedMeetings[k++] = meetings[j++];
		}
	}

	int tmp = i > midIndex ? j : i;

	while (k <= rightIndex) {
		sortedMeetings[k++] = meetings[tmp++];
	}

	// 재입력
	for (int i = leftIndex; i <= rightIndex; i++) {
		meetings[i] = sortedMeetings[i];
	}
}

void mergeSort(vector<pair<int, int>>& meetings, int leftIndex, int rightIndex) {
	int midIndex;

	if (leftIndex < rightIndex) {
		midIndex = (leftIndex + rightIndex) / 2;
		mergeSort(meetings, leftIndex, midIndex);
		mergeSort(meetings, midIndex + 1, rightIndex);
		merge(meetings, leftIndex, midIndex, rightIndex);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> meetings;

	int numOfMeetings;
	cin >> numOfMeetings;
	sortedMeetings = new pair<int, int>[numOfMeetings];

	int startTime, endTime;
	for (int i = 0; i < numOfMeetings; i++) {
		cin >> startTime >> endTime;
		meetings.push_back(make_pair(startTime, endTime));
	}

	//quickSort(meetings, 0, numOfMeetings - 1);
	mergeSort(meetings, 0, numOfMeetings - 1);

	int count = 1;
	pair<int, int> meeting = meetings[0];

	for (int i = 1; i < numOfMeetings; i++) {
		// 미팅 종료 시간이 다음 시작 시간보다 늦다면
		if (meeting.second > meetings[i].first)
			continue;

		meeting = meetings[i];
		++count;
	};

	cout << count;
	delete[] sortedMeetings;

	return 0;
}
