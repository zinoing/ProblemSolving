// 숫자짝꿍.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int visited[10];
vector<char> same;

bool cmp(char a, char b) {
    return a > b;
}

string solution(string X, string Y) {
    for (int i = 0; i < X.size(); i++) {
        int num = X[i] - '0';
        ++visited[num];
    }

    for (int i = 0; i < Y.size(); i++) {
        int num = Y[i] - '0';
        if (visited[num] > 0) {
            --visited[num];
            same.push_back(Y[i]);
        }
    }

    sort(same.begin(), same.end(), cmp);

    string answer = "";
    if (same.size() == 0) answer = "-1";
    else {
        for (int i = 0; i < same.size(); i++) {
            char num = same[i];
            if (num == '0' && i == 0) {
                answer = '0';
                break;
            }
            answer += num;
        }
    }

    return answer;
}

int main() {
    string X = "99999999999999999999";
    string Y = "99999999999999999999";
    cout << solution(X, Y);
    return 0;
}