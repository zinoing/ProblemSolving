// 5639.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nodes;

void postorder(int start, int end) {
	if (start == end) {
		cout << nodes[start] << "\n";
		return;
	}

	int root = start;
	int leftTreeEnd = end;
	int rightTreeStart = end + 1;

	for (int i = root + 1; i <= end; ++i) {
		// leftTree�� ������
		// rightTree�� �����Ǵ� ����
		if (nodes[root] < nodes[i]) {
			leftTreeEnd = i - 1;
			rightTreeStart = i;
			break;
		}
	}

	/*
	left tree ���
	right tree ��� 
	root ���
	*/
	if (root + 1 <= leftTreeEnd)
		postorder(root + 1, leftTreeEnd);
	if(rightTreeStart <= end)
		postorder(rightTreeStart, end);
	cout << nodes[root] << "\n";

	return;
}

int main() {
	int node = 0;

	while (cin >> node) {
		nodes.push_back(node);
	}

	postorder(0, nodes.size() - 1);

	return 0;
}