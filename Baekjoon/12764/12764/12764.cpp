// 12764.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;



struct Computer {
    int useCnt;
    int expectedEndTime;
};

int numOfPeople;
unordered_map<int, int> computerUses(numOfPeople);
priority_queue<int, vector<int>, greater<int>> startTimeQ;
priority_queue<int, vector<int>, greater<int>> endTimeQ;
vector<Computer> computers;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numOfPeople;

    for (int i = 0; i < numOfPeople; ++i) {
        int start, end;
        cin >> start >> end;
        computerUses.insert({ start, end });
        startTimeQ.emplace(start);
    }

    while (!startTimeQ.empty()) {
        int start = startTimeQ.top();
        startTimeQ.pop();

        // 첫 컴퓨터 사용자일 경우
        if (endTimeQ.empty()) {
            computers.push_back(Computer{1, computerUses[start] });
            endTimeQ.push(computerUses[start]);
            continue;
        }

        if (start < endTimeQ.top()) {
            computers.push_back(Computer{ 1, computerUses[start] });
            endTimeQ.push(computerUses[start]);
        }
        else if (start > endTimeQ.top()) {
            for(Computer& computer : computers)
            {
                if (computer.expectedEndTime <= start) {
                    computer.useCnt += 1;
                    computer.expectedEndTime = computerUses[start];
                    break;
                }
            }

            endTimeQ.pop();
            endTimeQ.push(computerUses[start]);
        }
    }

    cout << computers.size() << '\n';

    for (Computer computer : computers) {
        cout << computer.useCnt << ' ';
    }
}