// 1911.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> pools;
int ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        pools.push_back(make_pair(start, end));
    }
    
    sort(pools.begin(), pools.end());

    for (int i = 0; i < N; i++) {
        int dif = pools[i].second - pools[i].first;

        if (dif % L == 0) {
            ans += (dif / L);
            continue;
        }

        ans += (dif / L) + 1;

        if (i < N-1 && pools[i].second + L - 2 >= pools[i + 1].first) {
            pools[i+ 1].first = pools[i].second + L - 1;
        }
    }

    cout << ans;
}