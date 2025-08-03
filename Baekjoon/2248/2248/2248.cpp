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

    // 초기 이진수 배열을 0으로 설정
    string binary(N, '0');
    vector<string> binaryStrings;

    // 1을 L개 위치에 넣기
    for (int i = N - 1; i >= N - L; --i) {
        binary[i] = '1';
    }

    // next_permutation을 사용하여 가능한 모든 순열 생성하고 저장
    do {
        // '1'의 개수가 정확히 L개인 순열만 저장
        if (count(binary.begin(), binary.end(), '1') == L) {
            binaryStrings.push_back(binary);
        }
    } while (next_permutation(binary.begin(), binary.end()));

    // 1의 개수 기준으로 정렬
    sort(binaryStrings.begin(), binaryStrings.end(), [](const string& a, c)
}