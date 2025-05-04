// 7453.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	vector<int> d(n);
	vector<int> ab;
	vector<int> cd;
	map<int, int> sums;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			ab.push_back(a[i] + b[j]);
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cd.push_back(c[i] + d[j]);

		}
	}

	sort(ab.begin(), ab.end());

	long long cnt = 0;

	for (auto sum : cd) {
		auto range = upper_bound(ab.begin(), ab.end(), -sum) - lower_bound(ab.begin(), ab.end(), -sum);
		cnt += range;
	}

	cout << cnt;
}