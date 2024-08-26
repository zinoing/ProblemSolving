// 소수찾기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <cmath>
using namespace std;

bool visited[8];
set<int> numbersCreated;

void createNumber(vector<int> numbers, vector<bool> visited, vector<int> numberVec) {

    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            numberVec.push_back(numbers[i]);
            createNumber(numbers, visited, numberVec);
            numberVec.pop_back();
            visited[i] = false;
        }
    }

    if (!numberVec.empty()) {
        int number = 0;
        for (int i = 0; i < numberVec.size(); i++) {
            number += numberVec[i] * pow(10, numberVec.size() - 1 - i);
        }

        numbersCreated.insert(number);
    }
    return;
}

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= (int)sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    vector<int> numberVec;
    for (int i = 0; i < numbers.size(); i++) {
        int number = numbers[i] - '0';
        numberVec.push_back(number);
    }

    vector<int> newVec;
    vector<bool> visited(numberVec.size());
    createNumber(numberVec, visited, newVec);

    int cnt = 0;
    for (int num : numbersCreated) {

        if (isPrime(num)) {
            cout << num << '\n';
            ++cnt;

        }
    }

    int answer = cnt;
    return answer;
}

int main()
{
    string str = "121";
    cout << solution(str);
}