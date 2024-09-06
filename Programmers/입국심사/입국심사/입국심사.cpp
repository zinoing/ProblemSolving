// 입국심사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long minTime = 0;
    long long maxTime = *max_element(times.begin(), times.end()) * n;

    while (1) {
        long long mid = (minTime + maxTime) / 2;
        long long numOfPeople = 0;
        for (int time : times) {
            numOfPeople += mid / time;
        }

        // 시간이 너무 많을 경우
        if (numOfPeople >= n) {
            maxTime = mid - 1;
        }
        else {
            minTime = mid + 1;
        }

        if (minTime > maxTime) {
            cout << minTime << ' ' << maxTime << ' ' << mid;
            answer = minTime;
            break;
        }
    }
    return answer;
}