// 11758.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int main()
{
    vector<Point> points(3);
    float x, y;
    for (int i = 0; i < 3; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    int crossProduct = (points[1].x - points[0].x) * (points[2].y - points[1].y)
                        - (points[1].y - points[0].y) * (points[2].x - points[1].x);

    if (crossProduct > 0) cout << 1;
    else if (crossProduct == 0) cout << 0;
    else cout << -1;
    return 0;
}