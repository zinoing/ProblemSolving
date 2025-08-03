// 2281.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    vector<int> names(n);
    vector<pair<int, int>> dp(n, make_pair(0, m));

    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    dp[0].second -= names[0];
    int lineCnt = 0;
    for (int i = 1; i < n; ++i) {
        // 줄에 채워넣을 수 있는지 확인
        // 채워 넣을 수 있다면
        if (dp[lineCnt].second >= (1 + names[i])) {
            dp[lineCnt].second -= (1 + names[i]);
            continue; // 다음 이름으로 넘어감
        }
        // 채워 넣을 수 없다면 다음 줄로 넘어가야 함
        else {
            // 1. 해당 단어만 넘어가는 경우
            int nextLineSpaceOfFirstCase = m - (names[i]);

            // 2. 해당 단어의 이전 단어와 같이 넘어 가는 경우
            // i가 1 초과여야 하며 두 단어의 길이가 m을 넘어서는 안된다.(띄어쓰기 포함)
            int nextLineSpaceOfSecondCase = m;
            if (i != 1 && names[i - 1] + 1 + names[i] <= m) {
                nextLineSpaceOfSecondCase = m - (names[i - 1] + 1 + names[i]);
            }

            // 두 단어가 다음 줄로 내려 가는 경우가 여백의 제곱이 더 클 경우
            // 한 단어만 내려가는게 더 이득 => dp 초기화
            if (pow(dp[lineCnt].second, 2) + pow(nextLineSpaceOfFirstCase, 2) <= pow(dp[lineCnt].second + 1 + names[i - 1], 2) + pow(nextLineSpaceOfSecondCase, 2)) {
                dp[lineCnt + 1].first = i;
                dp[lineCnt + 1].second = nextLineSpaceOfFirstCase;
            }
            // 두 단어가 모두 내려가는게 이득인 경우
            else {
                dp[lineCnt].second = dp[lineCnt].second + 1 + names[i - 1];

                dp[lineCnt + 1].first = i - 1;
                dp[lineCnt + 1].second = nextLineSpaceOfSecondCase;
            }

            ++lineCnt;
        }
    }

    // 마지막 줄의 여백은 count 하지 않으니 마지막 줄에서 앞으로 옮길 수 있는 단어가 있는지 확인한다.
    // 또한 한 줄에서 끝날 수 있으니 dp[lineCnt].first != 0 조건으로 확인한다.
    if (dp[lineCnt].first != 0 && names[dp[lineCnt].first] < dp[lineCnt - 1].second) {
        dp[lineCnt - 1].second = dp[lineCnt - 1].second - (1 + names[dp[lineCnt].first]);

        dp[lineCnt].second += (1 + names[dp[lineCnt].first]);
        dp[lineCnt].first += 1;
    }

    long sum = 0;
    for (int i = 0; i < lineCnt; ++i) {
        sum += pow(dp[i].second, 2);
    }

    cout << sum;
}
