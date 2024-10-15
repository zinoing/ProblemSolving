// 예산.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());

    int sum = 0;
    int answer = 0;
    for (int i = 0; i < d.size(); ++i) {
        if (sum + d[i] > budget) {
            answer = i;
            break;
        }
        else sum += d[i];
    }
    if (answer == 0 && sum != 0) answer = d.size();

    return answer;
}