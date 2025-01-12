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
    // �� ���� ���ڰ� �θ� �ȴ�.
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

    // parent �ʱ�ȭ
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

    // �̹� ����� �˰� �ִ� ����鳢�� �׷��� �ξ���
    // �̶� root�� 0�� ��� 
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
        ���� ��ΰ� ó�� ��⸦ ��´ٸ� ������ party Ʈ���� ����� �ǰ�
        �Ѹ��̶� ����� �ȴٸ� true Ʈ���� ���Եǰ� �ȴ�.
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

    // ��ī����
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