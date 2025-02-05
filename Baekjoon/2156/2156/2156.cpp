#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> wines(10000);
	vector<int> dp(10000);

	fill(wines.begin(), wines.end(), 0);
	fill(dp.begin(), dp.end(), 0);

	for (int i = 0; i < n; ++i) {
		cin >> wines[i];
	}

	dp[0] = wines[0];
	dp[1] = wines[0] + wines[1];
	dp[2] = max(dp[1], max(wines[0] + wines[2], wines[1] + wines[2]));

	for (int i = 3; i < n; ++i) {
		dp[i] = max(dp[i - 3] + wines[i - 1] + wines[i], max(dp[i - 1], dp[i - 2] + wines[i]));
	}

	cout << dp[n - 1];

	return 0;
}