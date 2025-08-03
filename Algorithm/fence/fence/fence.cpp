// fence.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;


int solve(vector<int> h, int left, int right) {
    // 기저 사례: 판자가 하나밖에 없는 경우
    if (left == right) return h[left];
    // [left, mid], [mid + 1, right]의 두 구간으로 문제를 분할한다.
    int mid = (left + right) / 2;
    // 분할한 문제를 각개격파
    int ret = max(solve(h, left, mid), solve(h, mid + 1, right));
    // 부분 문제3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
    int lo = mid, hi = mid + 1;
    int height = min(h[lo], h[hi]);
    // [mid, mid+1]만 포함되는 너비 2인 사각형을 고려한다.
    ret = max(ret, height * 2);
    // 사각형이 입력 전체를 덮을 떄까지 확장해 나간다.
    while (left < lo || hi > right) {
        // 항상 높이가 더 높은 쪽으로 확장한다.
        if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) {
            ++hi;
            height = min(height, h[hi]);
        }
        else {
            --lo;
            height = min(height, h[lo]);
        }
        //확장한 후 사각형의 넓이
        ret = max(ret, height * (hi - lo + 1));
    }
    return ret;
}

int main()
{
    int C = 1;
    // cin >> C;

    for (int i = 0; i < C; ++i) {
        int N = 7;
        // cin >> N;
        //vector<int> fences(N, 0);
        vector<int> fences = { 2, 1, 4, 5, 1, 3, 3 };
        /*
        for (int j = 0; j < N; ++j) {
            int fence;
            cin >> fence;
            fences[i] = fence;
        }
        */
        cout << solve(fences, 0, N-1) << endl;
    }
}

// https://www.acmicpc.net/problem/6549