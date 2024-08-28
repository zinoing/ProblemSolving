// K번째수.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); i++) {
        vector<int> temp;
        for (int j = commands[i][0] - 1; j < commands[i][1]; j++) {
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end());

        answer.push_back(temp[commands[i][2] - 1]);
    }
    return answer;
}