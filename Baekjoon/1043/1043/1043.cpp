// 1043.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int parent[51];

int getParent(int idx) {
    return parent[idx];
}

int getRoot(int idx) {
    if (idx != parent[idx]) {
        parent[idx] = getRoot(parent[idx]);
    }
    return parent[idx];
}

void unionParent(int a, int b) {
    // 더 작은 숫자가 부모가 된다.
    if (a > b) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
    return;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // parent 초기화
    for (int i = 0; i < 51; ++i) {
        parent[i] = i;
    }

    int N, M;
    cin >> N >> M;

    int lieCnt = 0;

    int numOfPeopleWhoKnow;
    cin >> numOfPeopleWhoKnow;
    vector<int> peopleWhoKonw(numOfPeopleWhoKnow);

    for (int i = 0; i < numOfPeopleWhoKnow; ++i) {
        cin >> peopleWhoKonw[i];
    }

    // 이미 사실을 알고 있는 사람들끼리 그룹을 맺어줌
    // 이때 root는 0을 사용 
    int truthRoot = 0;
    for (int i = 0; i < numOfPeopleWhoKnow; ++i) {
        unionParent(getRoot(peopleWhoKonw[i]), truthRoot);
    }

    vector<pair<int, vector<int>>> parties;

    int numOfPeopleInParty = 0;
    for (int i = 0; i < M; ++i) {
        cin >> numOfPeopleInParty;

        vector<int> party;
        int person = -1;
        int partyRoot = -1;

        /*
        만약 모두가 처음 얘기를 듣는다면 공통의 party 트리가 생기게 되고
        한명이라도 사실을 안다면 true 트리에 포함되게 된다.
        */
        for (int j = 0; j < numOfPeopleInParty; ++j) {
            cin >> person;
            party.push_back(person);

            if (j == 0) {
                partyRoot = getRoot(person);
            }
            else unionParent(getRoot(person), partyRoot);
        }

        parties.push_back(make_pair(numOfPeopleInParty, party));
    }

    // 재카운팅
    for (int i = 0; i < M; ++i) {
        bool knowTrue = false;
        for (int j = 0; j < parties[i].first; ++j) {
            int root = getRoot(parties[i].second[j]);
            if (root == truthRoot) {
                knowTrue = true;
                break;
            }
        }

        if (knowTrue) {
            knowTrue = false;
        }
        else {
            ++lieCnt;
        }
    }

    cout << lieCnt;
    return 0;
}