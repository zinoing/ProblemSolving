// 프로세스.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    vector<int> cnt(101);
    queue<int*> prioritiesQueue;
    int* locationPriority = nullptr;

    for (int i = 0; i < priorities.size(); i++) {
        cnt[priorities[i]]++;
        prioritiesQueue.push(&priorities[i]);
        if (i == location) locationPriority = &priorities[i];
    }

    int answer = 1;
    while (!prioritiesQueue.empty()) {
        int* priorityPtr = prioritiesQueue.front();
        cout << *priorityPtr << '\n';

        bool rePush = false;
        for (int i = *priorityPtr + 1; i < 101; i++) {
            if (cnt[i] > 0) {
                prioritiesQueue.pop();
                prioritiesQueue.push(priorityPtr);
                rePush = true;
                cout << "repushed\n";
                break;
            }
        }

        if (rePush) continue;

        if (!rePush) {
            if (priorityPtr == locationPriority) break;

            prioritiesQueue.pop();
            cnt[*priorityPtr]--;
            ++answer;
        }
    }

    return answer;
}

int main()
{
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    int location = 0;
    cout << solution(priorities, location);
}
