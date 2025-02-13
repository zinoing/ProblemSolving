// 10451.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        vector<int> sequence(N + 1, 0);

        for (int j = 1; j <= N; ++j) {
            cin >> sequence[j];
        }

        int cnt = 0;
        for (int j = 1; j <= N; ++j) {

            // 방문한 노드라면 continue
            if (sequence[j] == -1) continue;

            int next = j;
            while (1) {
                // 이전에 이미 방문한 노드라면 사이클 존재
                if (sequence[next] == -1) {
                    ++cnt;
                    break;
                }
                else {
                    int temp = sequence[next];
                    sequence[next] = -1;
                    next = temp;
                }
            }
        }

        cout << cnt << "\n";
    }
}
