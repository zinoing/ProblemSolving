// 2248.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N, L, I;
    cin >> N >> L >> I;

    // �ʱ� ������ �迭�� 0���� ����
    string binary(N, '0');
    vector<string> binaryStrings;

    // 1�� L�� ��ġ�� �ֱ�
    for (int i = N - 1; i >= N - L; --i) {
        binary[i] = '1';
    }

    // next_permutation�� ����Ͽ� ������ ��� ���� �����ϰ� ����
    do {
        // '1'�� ������ ��Ȯ�� L���� ������ ����
        if (count(binary.begin(), binary.end(), '1') == L) {
            binaryStrings.push_back(binary);
        }
    } while (next_permutation(binary.begin(), binary.end()));

    // 1�� ���� �������� ����
    sort(binaryStrings.begin(), binaryStrings.end(), [](const string& a, c)
}