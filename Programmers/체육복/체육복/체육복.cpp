// 체육복.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

    #include <iostream>
    #include <string>
    #include <vector>
    #include <algorithm>
    #include <iostream>

    using namespace std;

    int solution(int n, vector<int> lost, vector<int> reserve) {
        int cnt = n - lost.size();
        int reserveIdx = 0;
        int lostIdx = 0;

        for (int i = 0; i < reserve.size(); i++) {
            for (int j = 0; j < lost.size(); j++) {
                if (reserve[i] == lost[j] && reserve[i] != -1) {
                    reserve[i] = -1;
                    lost[j] = -1;
                    ++reserveIdx;
                    ++lostIdx;
                    ++cnt;
                }
            }
        }
        sort(reserve.begin(), reserve.end());
        sort(lost.begin(), lost.end());

        while (reserveIdx < reserve.size() && lostIdx < lost.size()) {
            while (reserveIdx < reserve.size() && reserve[reserveIdx] < lost[lostIdx] - 1) {
                ++reserveIdx;
            }

            if (reserveIdx >= reserve.size()) break;

            while (lostIdx < lost.size() && lost[lostIdx] < reserve[reserveIdx] - 1) {
                ++lostIdx;
            }

            if (lostIdx >= lost.size()) break;

            if ((reserve[reserveIdx] >= lost[lostIdx] - 1 && reserve[reserveIdx] <= lost[lostIdx] + 1) || (lost[lostIdx] >= reserve[reserveIdx] - 1 && lost[lostIdx] <= reserve[reserveIdx] + 1)) {
                ++lostIdx;
                ++reserveIdx;
                ++cnt;
            }
        }

        int answer = cnt;
        return answer;
    }


/*
chatGPT 코드

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // Step 1: 초기화
    vector<int> lost_adjusted;
    vector<int> reserve_adjusted;

    // Step 2: 체육복을 도난당한 학생 중 여벌 체육복을 가진 학생 제거
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 여벌 체육복을 가진 학생이 도난당한 경우를 처리
    for(int i = 0; i < reserve.size(); i++) {
        if(find(lost.begin(), lost.end(), reserve[i]) != lost.end()) {
            // 여벌 체육복을 가진 학생이 도난당한 경우
            lost.erase(find(lost.begin(), lost.end(), reserve[i]));
            reserve[i] = -1; // 해당 학생은 더 이상 여벌 체육복을 나눌 수 없음
        }
    }

    // 여벌 체육복을 가진 학생 중 여전히 여벌이 있는 학생들
    for(int i = 0; i < reserve.size(); i++) {
        if(reserve[i] != -1) reserve_adjusted.push_back(reserve[i]);
    }

    // 도난당한 체육복을 가진 학생들
    for(int i = 0; i < lost.size(); i++) {
        lost_adjusted.push_back(lost[i]);
    }

    // Step 3: 체육복을 빌려줄 수 있는 경우 처리
    int answer = n - lost_adjusted.size(); // 초기 체육복이 있는 학생 수

    for(int i = 0; i < reserve_adjusted.size(); i++) {
        if(find(lost_adjusted.begin(), lost_adjusted.end(), reserve_adjusted[i] - 1) != lost_adjusted.end()) {
            // 바로 앞 번호 학생이 도난당했으면 빌려줌
            answer++;
            lost_adjusted.erase(find(lost_adjusted.begin(), lost_adjusted.end(), reserve_adjusted[i] - 1));
        } else if(find(lost_adjusted.begin(), lost_adjusted.end(), reserve_adjusted[i] + 1) != lost_adjusted.end()) {
            // 바로 뒤 번호 학생이 도난당했으면 빌려줌
            answer++;
            lost_adjusted.erase(find(lost_adjusted.begin(), lost_adjusted.end(), reserve_adjusted[i] + 1));
        }
    }

    return answer;
}

*/