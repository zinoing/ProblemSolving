// 1789.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
unsigned int S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S;
	
	long long sum = 0;
	unsigned int cnt = 0;
	for (unsigned int i = 1; i <= S; ++i) {
		sum += i;
		++cnt;

		if (sum > S) {
			--cnt;
			break;
		}
	}

	cout << cnt;

	return 0;
}