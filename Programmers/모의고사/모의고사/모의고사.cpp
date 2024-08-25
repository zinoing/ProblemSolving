// 모의고사.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//vector<int> answers;
//
//vector<int> solution(vector<int> answers) {
//    int first[10] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
//    int second[8] = { 2, 1, 2, 3, 2, 4, 2, 5 };
//    int third[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
//    int firstIdx = 0;
//    int secondIdx = 0;
//    int thirdIdx = 0;
//    int firstCnt = 0;
//    int secondCnt = 0;
//    int thirdCnt = 0;
//
//    for (int i = 0; i < answers.size(); i++) {
//        if (firstIdx == 10) {
//            firstIdx = 0;
//            thirdIdx = 0;
//        }
//
//        if (secondIdx == 8) {
//            secondIdx = 0;
//        }
//
//        if (first[firstIdx] == answers[i]) {
//            ++firstCnt;
//        }
//
//
//        if (second[secondIdx] == answers[i]) {
//            ++secondCnt;
//        }
//
//        if (third[thirdIdx] == answers[i]) {
//            ++thirdCnt;
//        }
//
//        ++firstIdx;
//        ++secondIdx;
//        ++thirdIdx;
//    }
//
//    vector<pair<int, int>> scores;
//    scores.push_back(make_pair(firstCnt, 1));
//    scores.push_back(make_pair(secondCnt, 2));
//    scores.push_back(make_pair(thirdCnt, 3));
//
//    sort(scores.begin(), scores.end());
//    int max = scores[2].first;
//
//    vector<int> answer;
//
//    for (int i = 0; i < 3; i++) {
//        if (max == scores[i].first) {
//            answer.push_back(scores[i].second);
//        }
//    }
//
//    sort(answer.begin(), answer.end());
//    return answer;
//}

vector<int> solution(vector<int> answers) {
    vector<vector<int>> pattern{
    {1, 2, 3, 4, 5, 1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };
   
    vector<int> cnt(3);

    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < 3; j++) {
            if (pattern[j][i % pattern[j].size()] == answers[i]) {
                ++cnt[j];
            }
        }
    };

    int maxCnt = max({ cnt[0], cnt[1], cnt[2] });

    vector<int> answer;

    for (int i = 0; i < 3; i++) {
        if (maxCnt == cnt[i]) {
            answer.push_back(i);
        }
    }

    sort(answer.begin(), answer.end());
    return answer;
}
