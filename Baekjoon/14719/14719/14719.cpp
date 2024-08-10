// 14719.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int H, W;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> blocks;
    int totalRainWater = 0;

    cin >> H >> W;

    int input;
    for (int i = 0; i < W; i++) {
        cin >> input;
        blocks.push_back(input);
    }

    for (int i = 0; i < W; i++) {
        int leftMax = blocks[i];
        int rightMax = blocks[i];

        for (int j = 0; j < i; j++) {
            leftMax = max(leftMax, blocks[j]);
        }
        for (int j = i + 1; j < W; j++) {
            rightMax = max(rightMax, blocks[j]);
        }

        int lowerMax = leftMax < rightMax ? leftMax : rightMax;
        totalRainWater += (lowerMax - blocks[i]);
    }

    cout << totalRainWater;
}