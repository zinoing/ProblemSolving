// 기능개발.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    queue<pair<int, int>> progressesQueue;

    for (int i; i < progresses.size(); i++) {
        progressesQueue.push(make_pair(progresses[i], speeds[i]));
    }
    vector<int> answer;
    int day = 1;
    int cnt = 0;
    while (1) {

        int progress = progressesQueue.front().first + day * progressesQueue.front().second;

        if (progress >= 100) {
            progressesQueue.pop();
            ++cnt;
            continue;
        }

        if (cnt != 0) {
            answer.push_back(cnt);
            cnt = 0;
        }
        ++day;

        if (progressesQueue.empty()) {
            break;
        }
    }

    return answer;
}

int main()
{
    std::cout << "Hello World!\n";
}