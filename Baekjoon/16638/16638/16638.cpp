// 16638.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

int N;
string expression;
vector<int> numbers;
vector<char> operators;
int maxVal = INT_MIN;

int calculate(int a, int b, char op) {
	switch (op) {
	case '+':
		a += b;
		break;
	case '-':
		a -= b;
		break;
	case '*':
		a *= b;
		break;
	default:
		break;
	}

	return a;
}

void dfs(int start, int val) {
	if (start >= numbers.size()) {
		if (maxVal < val) {
			maxVal = val;
		}
		return;
	}

	// 괄호를 닫았을 경우
	if (start < numbers.size() - 1) {
		dfs(start + 2, calculate(val, calculate(numbers[start], numbers[start + 1], operators[start]), operators[start - 1]));
	}

	// 괄호를 하지 않고 넘어가는 경우
	int idx = start;
	int temp = numbers[idx];
	while (idx < operators.size()) {
		if (operators[idx] == '*') {
			temp *= numbers[++idx];
		}
		else break;
	}
	dfs(idx + 1, calculate(val, temp, operators[start - 1]));

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> expression;

	for (auto c : expression) {
		if (c >= '1' && c <= '9') {
			numbers.push_back(c - '0');
		}
		else {
			operators.push_back(c);
		}
	}

	dfs(0, 0);
	cout << maxVal;
}