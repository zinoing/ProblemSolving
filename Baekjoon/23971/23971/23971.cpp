// 23971.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> Pos;

int H, W, N, M;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W >> N >> M;
    
    int x = 0;
    int y = 0;
    while (x <= W - M - 2 || y <= H - N - 2) {
        if(x <= W - M - 2)
            x += (M + 1);

        if(y <= H - N - 2)
            y += (N + 1);
    }

    cout << (x / (M + 1) + 1) * (y / (N + 1) + 1);

    return 0;
}