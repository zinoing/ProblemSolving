#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int dp[41] = { 0, };
    vector<int> vipGap;
    int ans = 1;

    int numOfVIP;
    cin >> numOfVIP;

    int previous = 0;
    for (int i = 0; i < numOfVIP; i++) {
        int VIP;
        cin >> VIP;
        vipGap.push_back(VIP - previous - 1);
        previous = VIP;

        if (i == numOfVIP - 1) {
            vipGap.push_back(N - previous);
        }
    }

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i < 41; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    for (int i = 0; i < vipGap.size(); i++) {
        ans *= dp[vipGap[i]];
    }

    if (vipGap.size() == 0) {
        ans = dp[N];
    }
    cout << ans;

    return 0;
}