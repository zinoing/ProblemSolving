// 2304.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> pillars;
int numOfPillars;
int maxHeightOfPillar = 0;
int totalArea;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> numOfPillars;

    for (int i = 0; i < numOfPillars; i++) {
        int xPos, height;
        cin >> xPos >> height;
        pillars.push_back(make_pair(xPos, height));

        if (maxHeightOfPillar < height) {
            maxHeightOfPillar = pillars[i].second;
        }
    }

    sort(pillars.begin(), pillars.end());

    // 정방향으로 계산
    int heightOfPreviousPillar = pillars[0].second;
    int xPosOfPreviousPillar = pillars[0].first;
    int width, area;

    int idx = 0;
    while (pillars[idx].second != maxHeightOfPillar) {
        ++idx;
        width = pillars[idx].first - xPosOfPreviousPillar;
        area = width * heightOfPreviousPillar;
        totalArea += area;

        if (pillars[idx].second > heightOfPreviousPillar) {
            heightOfPreviousPillar = pillars[idx].second;
        }

        xPosOfPreviousPillar = pillars[idx].first;
    }
    pair<int, int> highestPillarOnLeftSide = pillars[idx];

    // 반대편에서 다시 계산
    heightOfPreviousPillar = pillars[numOfPillars - 1].second;
    xPosOfPreviousPillar = pillars[numOfPillars - 1].first;

    idx = numOfPillars - 1;
    while (pillars[idx].second != maxHeightOfPillar) {
        --idx;
        width = abs(pillars[idx].first - xPosOfPreviousPillar);
        area = width * heightOfPreviousPillar;
        totalArea += area;

        if (pillars[idx].second > heightOfPreviousPillar) {
            heightOfPreviousPillar = pillars[idx].second;
        }

        xPosOfPreviousPillar = pillars[idx].first;
    }
    pair<int, int> highestPillarOnRightSide = pillars[idx];

    // 만약 최고 높이의 기둥이 여러 개 있을 시 이 두 기둥 간의 넓이 확인
    int interval = (highestPillarOnRightSide.first - highestPillarOnLeftSide.first + 1) * maxHeightOfPillar;
    totalArea += interval;

    cout << totalArea;

    return 0;
}