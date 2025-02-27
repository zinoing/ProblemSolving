// 16638.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <stack>
#include <climits>

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

// 연산자 우선순위
int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

vector<char> infixToPostfix(vector<char> infix) {
	stack<char> postfixStack;
	vector<char> postFixVec;

	for (auto c : infix) {
		if (isdigit(c)) {
			postFixVec.push_back(c);
		}
		else if (c == '(') {
			postfixStack.push(c);
		}
		else if (c == ')') {
			while (1) {
				if (postfixStack.top() == '(') {
					postfixStack.pop();
					break;
				}
				postFixVec.push_back(postfixStack.top());
				postfixStack.pop();
			}
		}
		else {
			while(!postfixStack.empty() && precedence(postfixStack.top()) >= precedence(c)) {
				postFixVec.push_back(postfixStack.top());
				postfixStack.pop();
			}
			postfixStack.push(c);
		}
	}

	while (!postfixStack.empty()) {
		postFixVec.push_back(postfixStack.top());
		postfixStack.pop();
	}

	return postFixVec;
}

int calculatePostfix(vector<char> postfix) {
	stack<int> numbers;

	for (auto c : postfix) {
		if (isdigit(c)) {
			numbers.push(c - '0');
		}
		else {
			int b = numbers.top(); numbers.pop();
			int a = numbers.top(); numbers.pop();
			numbers.push(calculate(a, b, c));
		}
	}

	return numbers.top();  // 최종 결과 반환
}

void dfs(int start, vector<char> formula) {

	if (start == operators.size()) {
		formula.push_back(numbers[start] + '0');
	}

	if (start >= operators.size()) {
		maxVal = max(maxVal, calculatePostfix(infixToPostfix(formula)));
		return;
	}

	// 괄호를 넣지 않을 경우
	formula.push_back(numbers[start] + '0');
	if(start < operators.size())
		formula.push_back(operators[start]);
	dfs(start + 1, formula);
	formula.pop_back();
	if (start < operators.size())
		formula.pop_back();

	// 괄호를 넣을 경우
	formula.push_back('(');
	formula.push_back(numbers[start] + '0');
	formula.push_back(operators[start]);
	formula.push_back(numbers[start + 1] + '0');
	formula.push_back(')');

	if (start + 2 < numbers.size()) {
		formula.push_back(operators[start + 1]);
	}

	dfs(start + 2, formula);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> expression;

	for (auto c : expression) {
		if (isdigit(c)) {
			numbers.push_back(c - '0');
		}
		else {
			operators.push_back(c);
		}
	}

	dfs(0, vector<char>());
	cout << maxVal;
}