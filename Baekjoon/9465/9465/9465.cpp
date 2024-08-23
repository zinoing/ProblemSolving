// 9465.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
using namespace std;

int stickers[2][100001];
int scores[2][100001];
int height = 2;
int width;
int maxValue = 0;

int TakeOffSticker(int y, int x) {
    if (x > width - 1) {
        return 0;
    }

    if (scores[y][x] != -1)
        return scores[y][x];

    scores[y][x] = stickers[y][x] + max(TakeOffSticker(1 - y, x + 1), TakeOffSticker(1 - y, x + 2));

    return scores[y][x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> width;

        // stickers 입력
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < width; k++) {
                int sticker;
                cin >> sticker;
                stickers[j][k] = sticker;

                // scores 초기화  
                scores[j][k] = -1;
            }
        }

        // 스티커를 찢을 수 있는 최대 개수: width
        // 스티커를 찢을 수 있는 최소 개수: width / 2 + 1

        // 왼쪽 부터 오른쪽 순으로 스티커를 뜯는다고 가정,
        // 나올 수 있는 첫번 째 경우의 수는 width=1을 제외하고는 2가지

        // 찢을 때 score을 누적해서 입력
        // 만약 찢으려고 하는 스티커의 누적 score가 현재 누적 score보다 높다면 즉시 종료
        // 만약 다 찢었다면 최종 score 비교 후 최댓값 선택

        cout << max(TakeOffSticker(0, 0), TakeOffSticker(1, 0)) << '\n';
    }
}