// 가장 큰 수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return true;

    if (a.first == b.first) {
        string strA = to_string(a.second);
        string strB = to_string(b.second);

        string newStrAB = strA + strB;
        string newStrBA = strB + strA;

        return stoi(newStrAB) > stoi(newStrBA);
    }
}

string solution(vector<int> numbers) {
    vector<pair<int, int>> numbersWithFront;
    for (int i = 0; i < numbers.size(); i++) {
        int front = 0;
        int temp = numbers[i];
        while (1) {
            front = temp;
            temp /= 10;
            if (temp == 0) break;
        }
        numbersWithFront.push_back(make_pair(front, numbers[i]));
    }

    sort(numbersWithFront.begin(), numbersWithFront.end(), comp);

    string answer = "";
    for (int i = 0; i < numbersWithFront.size(); i++) {
        string str = to_string(numbersWithFront[i].second) + ' ';
        answer += str;
    }

    if (answer[0] == '0') answer = '0';
    return answer;
}

int main()
{
    vector<int> numbers = { 67,676,677 };
    //vector<int> numbers = { 979, 97, 978, 81, 818, 817 };
    //vector<int> numbers = { 123,1232 };
    //vector<int> numbers = { 1000, 111, 110, 101, 100, 11, 10, 1, 0 };
    string answer = solution(numbers);
    cout << answer;
}