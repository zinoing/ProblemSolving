// 2501.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	int cnt = 0;
	for (int i = 1; i <= N; ++i) {
		if (N % i == 0) ++cnt;
		if (cnt == K) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}