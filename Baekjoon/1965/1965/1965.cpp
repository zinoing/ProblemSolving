#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> v(N);
	for (auto& x : v) cin >> x;
	for (int i = 0; i < N; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
		}
	}
	cout << *max_element(dp, dp + N + 1) + 1;
}