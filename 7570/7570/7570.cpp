// 7570.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int length[1000001];
int maxLength = 1;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int numOfChildren;
    cin >> numOfChildren;

    int child;
    for (int i = 0; i < numOfChildren; i++) {
        cin >> child;

        length[child] = length[child - 1] + 1;

        if (length[child] > maxLength) {
            maxLength = length[child];
        }
    }

    cout << numOfChildren - maxLength;
}
