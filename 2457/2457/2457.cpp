// 2457.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int startMonth = 3;
int startDate = 1;
int endMonth = 11;
int endDate = 30;
int ans = 0;

struct Flower {
    int floweringMonth;
    int floweringDate;
    int fallingMonth;
    int fallingDate;

    Flower() {}

    Flower(int startMonth, int startDate, int endMonth, int endDate) {
        floweringMonth = startMonth;
        floweringDate = startDate;
        fallingMonth = endMonth;
        fallingDate = endDate;
    }
};

struct CompareFlowerWithFloweringTime {
    bool operator()(const Flower& f1, const Flower& f2) {
        if (f1.floweringMonth == f2.floweringMonth) {
            return f1.floweringDate > f2.floweringDate;
        }
        return f1.floweringMonth > f2.floweringMonth;
    }
};

struct CompareFlowerWithFallingTime {
    bool operator()(const Flower& f1, const Flower& f2) {
        if (f1.fallingMonth == f2.fallingMonth) {
            return f1.fallingDate < f2.fallingDate;
        }
        return f1.fallingMonth < f2.fallingMonth;
    }
};

int main()
{   
    int previousFallingMonth = startMonth;
    int previousFallingDate = startDate;

    int numOfFlowerTypes;
    cin >> numOfFlowerTypes;

    priority_queue<Flower, vector<Flower>, CompareFlowerWithFloweringTime> flowers;
    vector<Flower> determinedFlowers;
    
    for (int i = 0; i < numOfFlowerTypes; i++) {
        Flower newFlower;
        cin >> newFlower.floweringMonth >> newFlower.floweringDate >> newFlower.fallingMonth >> newFlower.fallingDate;
        flowers.push(newFlower);
    }

    // 3월 1일 이전에 핀 꽃이 없다면
    if (flowers.top().floweringMonth > startMonth || ((flowers.top().floweringMonth == startMonth) && flowers.top().floweringDate > startDate)) {
        cout << ans;
        return 0;
    }

    priority_queue<Flower, vector<Flower>, CompareFlowerWithFallingTime> tempFlowers;

    for (int i = 0; i < numOfFlowerTypes; i++) {
        Flower flower = flowers.top();

        // 이전의 꽃이 지는 날보다 빨리 핀다면
        if (flower.floweringMonth < previousFallingMonth || ((flower.floweringMonth == previousFallingMonth) && flower.floweringDate <= previousFallingDate)) {
            tempFlowers.push(flower);
        }
        // 이전의 꽃이 지는 날보다 늦게 핀다면
        else {
            if (tempFlowers.empty()) {
                continue;
            }

            Flower nextFlower = tempFlowers.top();
            determinedFlowers.push_back(nextFlower);
            
            if((nextFlower.fallingMonth > endMonth)
                || ((nextFlower.fallingMonth == endMonth) && nextFlower.fallingDate > endDate)) {
                break;
            }
            
            previousFallingMonth = nextFlower.fallingMonth;
            previousFallingDate = nextFlower.fallingDate;

            int size = tempFlowers.size();
            for (int j = 0; j < size; j++) {
                tempFlowers.pop();
            }

            i -= 1;
            continue;
        }

        if (i == numOfFlowerTypes - 1 && !tempFlowers.empty()) {
            determinedFlowers.push_back(tempFlowers.top());
        }
        flowers.pop();
    }

    if ((determinedFlowers.back().fallingMonth < endMonth)
         || ((determinedFlowers.back().fallingMonth == endMonth) && determinedFlowers.back().fallingDate <= endDate)) {
        cout << ans;
        return 0;
    }

    ans = determinedFlowers.size();
    cout << ans << '\n';

    /*
    int size = determinedFlowers.size();
    for_each(determinedFlowers.begin(), determinedFlowers.end(), [](Flower& flower)
        {cout << flower.floweringMonth << ", " << flower.floweringDate << "........... " << flower.fallingMonth << ", " << flower.fallingDate << '\n'; });
    */
}