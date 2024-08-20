// 1781.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define MAX 200001
#include <iostream>
#include <queue>
using namespace std;

int N;

struct Problem {
    int m_deadline;
    int m_numOfAwards;
    Problem(int deadline, int numOfAwards) : m_deadline(deadline), m_numOfAwards(numOfAwards) {}
};

struct cmp {
    bool operator() (Problem a, Problem b) {
        if (a.m_deadline == b.m_deadline)
            return a.m_numOfAwards > b.m_numOfAwards;
        return a.m_deadline > b.m_deadline;
    }
};

struct chooseLessAward {
    bool operator() (Problem a, Problem b) {
        return a.m_numOfAwards > b.m_numOfAwards;
    }
};

priority_queue<Problem, vector<Problem>, cmp> problems_pq;

void solve() {
    priority_queue<Problem, vector<Problem>, chooseLessAward> temp;
    
    int previousDeadline = 0;
    while (!problems_pq.empty()) {
        Problem pr = problems_pq.top();
        problems_pq.pop();
        int deadline = pr.m_deadline;

        if (deadline > previousDeadline) {
            while (temp.size() > previousDeadline) {
                temp.pop();
            }
        }

        temp.push(pr);
        previousDeadline = deadline;

        if (problems_pq.empty()) {
            while (temp.size() > previousDeadline) {
                temp.pop();
            }
        }
    }

    int sum = 0;
    while (!temp.empty()) {
        Problem pr = temp.top();
        temp.pop();
        sum += pr.m_numOfAwards;
    }

    cout << sum;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        int deadline;
        int numOfAwards;
        cin >> deadline >> numOfAwards;
        Problem problem = Problem(deadline, numOfAwards);
        problems_pq.push(problem);
    }

    solve();
}