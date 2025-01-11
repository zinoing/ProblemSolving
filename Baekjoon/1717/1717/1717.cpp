// 1717.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int parent[1000001];

int getParent(int idx) {
    return parent[idx];
}

void unionParent(int a, int b) {
    // �� ���� ���ڰ� parent�� �ȴ�.
    if (a > b) {
        parent[a] = b;
    }
    else {
        parent[b] = a;
    }
    return;
}

int findRootParent(int idx) {
    if (parent[idx] != idx) {
        parent[idx] = findRootParent(parent[idx]);  // ��� ����
    }
    return parent[idx];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    // parent �ʱ�ȭ
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) {
        int command, a, b;
        cin >> command >> a >> b;

        if (command == 0) {
            unionParent(findRootParent(a), findRootParent(b));
        }
        else {
            int rootA = findRootParent(a);
            int rootB = findRootParent(b);
            if (rootA != rootB) {
                cout << "NO\n";
            }
            else {
                cout << "YES\n";
            }
        }
    }
}