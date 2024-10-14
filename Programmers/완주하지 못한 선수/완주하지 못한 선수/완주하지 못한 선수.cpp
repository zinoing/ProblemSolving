// 완주하지 못한 선수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> people;
    for (string person : participant) {
        people[person] += 1;
    }

    for (string person : completion) {
        people[person] -= 1;
    }

    string answer = "";
    for (pair<string, int>person : people) {
        if (people[person.first] > 0) {
            answer = person.first;
            break;
        }
    }
    return answer;
}