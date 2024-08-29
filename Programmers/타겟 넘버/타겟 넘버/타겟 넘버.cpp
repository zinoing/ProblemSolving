// 타겟 넘버.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int currentValue, int target, int cnt, int n, int* answer) {
    if (cnt == n) {
        if (currentValue == target) {
            *answer += 1;
        }
        return;
    }

    dfs(numbers, currentValue + numbers[cnt], target, cnt + 1, n, answer);
    dfs(numbers, currentValue - numbers[cnt], target, cnt + 1, n, answer);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, 0, target, 0, numbers.size(), &answer);
    return answer;
}