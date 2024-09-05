// 구명보트.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;

    int numOfPeople = people.size();
    int firstPerson = 0;
    int lastPerson = numOfPeople - 1;
    for (int i = lastPerson; i >= firstPerson; i--) {
        if (people[firstPerson] + people[i] <= limit) {
            ++firstPerson;
        }
        ++answer;
    }

    return answer;
}