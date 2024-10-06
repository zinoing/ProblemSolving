// 디스크 컨트롤러.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct CompWithEndTime {
    bool operator() (const vector<int> a, const vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    // 작업들을 시간 순으로 정렬한다.
    sort(jobs.begin(), jobs.end());
    
    // 작업 시간 기준으로 오름차순으로 정렬하는 우선순위 큐 선언
    priority_queue<vector<int>, vector<vector<int>>, CompWithEndTime> jobsSortedByWorkTime;

    int time = 0;
    int waitingTime = 0;
    int sumOfWaitingTime = 0;

    int n = jobs.size();
    int i = 0;

    while (n > i || !jobsSortedByWorkTime.empty()) {

        // time보다 일찍 시작되는 작업들은 우선순위 큐에 삽입
        if (n>i && time >= jobs[i][0]) {
            jobsSortedByWorkTime.push(jobs[i]);
            ++i;
            continue;
        }
        
        if (!jobsSortedByWorkTime.empty()) {
            auto nextJob = jobsSortedByWorkTime.top();
            jobsSortedByWorkTime.pop();

            cout << nextJob[0] << ", " << nextJob[1] << endl;
            time += nextJob[1];
            waitingTime = time - nextJob[0];
            sumOfWaitingTime += waitingTime;
            cout << "sumOfWaitingTime " << sumOfWaitingTime << endl;
        }
        else {
            time = jobs[i][0];
        }
    }

    int answer = sumOfWaitingTime / n;
    return answer;
}



int main() {
    vector<vector<int>> jobs = { {0, 3}, {1, 9}, {2, 6} };
    /*
    1: 5
    2: 8 + 1 // 16
    3: 7 + 6

    {{0, 3}, {10, 1}} => 2
    {{7, 8}, {3, 5}, {9, 6}} => 9
    1: {3, 5} => 5
    2: {7, 8} => 1 + 8 = 9
    3: {9, 6} => 7 + 6 = 13

    1: {3, 5} => 5
    2: {9, 6} => 6
    3: {7, 8} => 8 + 8 => 18

    {{1, 4}, {7, 9}, {1000, 3}} => 5
    {{0, 1}, {2, 2}, {2, 3}} => 2
    {{0, 3}, {1, 9}, {2, 6}} => 9
    */

    cout << solution(jobs);
    return 0;
}