// 16637.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int N;
string expression;
int maxVal = INT_MIN;

vector<int> numbers;
vector<char> operators;

void dfs(int start, int val) {
    if (start >= numbers.size()) {
        if (val > maxVal) {
            maxVal = val;
        }
        return;
    }

    int temp = numbers[start];

    if (start < operators.size()) {
        switch (operators[start]) {
        case '*':
            temp *= numbers[start + 1];
            break;
        case '+':
            temp += numbers[start + 1];
            break;
        case '-':
            temp -= numbers[start + 1];
            break;
        }

        int tempVal = val;
        switch (operators[start - 1]) {
        case '*':
            tempVal *= temp;
            break;
        case '+':
            tempVal += temp;
            break;
        case '-':
            tempVal -= temp;
            break;
        }

        dfs(start + 2, tempVal);
    }

    switch (operators[start - 1]) {
    case '*':
        val *= numbers[start];
        break;
    case '+':
        val += numbers[start];
        break;
    case '-':
        val -= numbers[start];
        break;
    }

    // 괄호를 하지 않고 다음으로 넘겨버리는 dfs
    dfs(start + 1, val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cin >> expression;

    for (int i = 0; i < expression.size(); ++i) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            numbers.push_back(expression[i] - '0');
        }
        else {
            operators.push_back(expression[i]);
        }
    }

    int start = 1;

    dfs(1, numbers[0]);

    cout << maxVal;

}