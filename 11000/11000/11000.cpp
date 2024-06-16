// 11000.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Class {
    int startTime;
    int endTime;

    Class(int startTime, int endTime) {
        this->startTime = startTime;
        this->endTime = endTime;
    }
};

struct Cmp {
    bool operator() (const Class& c1, const Class& c2) {
        if (c1.startTime == c2.startTime) {
            return c1.endTime > c2.endTime;
        }
        return c1.startTime > c2.startTime;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numOfClasses;
    cin >> numOfClasses;

    /*
    priority_queue < Class, vector<Class>, Cmp> classes;
    vector<vector<Class>> classrooms;

    for (int i = 0; i < numOfClasses; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        classes.push(Class(startTime, endTime));
    }

    for (int i = 0; i < numOfClasses; i++) { 
        Class selectedClass = classes.top();
        classes.pop();
        
        if (classrooms.empty()) {
            vector<Class> vec;
            vec.push_back(selectedClass);
            classrooms.push_back(vec);
            continue;
        }

        int numOfClassrooms = classrooms.size();
        bool needNewClassroom = false;
        for (int j = 0; j < numOfClassrooms; j++) {
            if (classrooms[j].back().endTime <= selectedClass.startTime) {
                classrooms[j].push_back(selectedClass);
                break;
            }

            if (j == numOfClassrooms - 1)
                needNewClassroom = true;
        }

        if (needNewClassroom) {
            vector<Class> vec;
            vec.push_back(selectedClass);
            classrooms.push_back(vec);
            needNewClassroom = false;
        }
    }

    cout << classrooms.size();
    */

    vector<pair<int, int>> classes;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < numOfClasses; i++) {
        int startTime, endTime;
        cin >> startTime >> endTime;
        classes.push_back(make_pair(startTime, endTime));
    }

    sort(classes.begin(), classes.end());

    for (int i = 0; i < numOfClasses; i++) {
        pq.push(classes[i].second);
        if (pq.top() <= classes[i].first) {
            pq.pop();
        }
    }

    cout << pq.size();
}
