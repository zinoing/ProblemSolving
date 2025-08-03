// 16565.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define TOTAL_CARDS 52
#define MOD         10007

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
��ȭ��
13Ci * (52 - i*4)C(n - i*4) - (13C(i+1) * (52 - (i+1)*4)C(n - (i+1)*4))
*/

int numberOfCombinations(int n, int r) {
    if (r > n) return 0;
    long long result = 1;

    for (int i = 0; i < r; ++i) {
        result = (result * (n - i)) % MOD;
    }

    long long denom = 1;
    for (int i = 1; i <= r; ++i) {
        denom = (denom * i) % MOD;
    }

    long long denomInv = 1;
    for (int i = 0; i < MOD - 2; ++i) {
        denomInv = (denomInv * denom) % MOD;
    }

    return (result * denomInv) % MOD;
}

int solve(int n) {
    // 4�� �̸����� ���� �� four of a kind�� �ϼ� ��ų �� ����.
    if (n < 4) return 0;

    // 4���� ���� �� 13������ four of a kind�� �ϼ� ��ų �� �ִ�.
    if (n == 4) return 13;

    long long outcomes = 0;

    for (int i = 1; i <= n / 4; ++i) {
        long long comb1 = numberOfCombinations(13, i);
        long long comb2 = numberOfCombinations(TOTAL_CARDS - 4 * i, n - 4 * i);

        if (i % 2 == 0) {
            outcomes = (outcomes - comb1 * comb2) % MOD; // ¦���� ��� ����
        }
        else {
            outcomes = (outcomes + comb1 * comb2) % MOD; // Ȧ���� ��� ���ϱ�
        }
    }

    return (outcomes + MOD) % MOD;  // ���� ó��
}

int main()
{
    int n;
    cin >> n;

    cout << solve(n);
}

/*
n�� 5�� ���,
13 * (52 - 4) = 624

n�� 6�� ���,
13 * (52 - 4) * (52 - 5) / 2! = 14664

n�� 7�� ���, 
13 * (52 - 4) * (52 - 5) * (52 - 6) / 3! = 224848

n�� 8�� ���,
13 * (52 - 4) * (52 - 5) * (52 - 6) * (52 - 7) / 4! = 2529540
���� ���� Ǯ�� Ʋ��, why => 8�� ī�� �� 4,4�� ��ī�� �ΰ��� ��찡 ��ġ�� ��� �߻� ���� �̸� �������־�� �Ѵ�.
13���� ���� ���� �߿� 2���� �̴� ����� �� 13C2 = 13 * 6 = 78
2529540 - 78 = 2529462

n�� 12�� ���,
13C1 * 48C8 - (13C2 * 44C4) + 13C3
= 13 * 377348994 - 78 * 135751 + 286
= 4894948630

n�� 20�� ���,
13C1 * 48C16 - (13C2 * 44C6) + 13C3 * 40C2
= 13 * 6540715896 - 78 * 7059052 + 286 * 780
= 84478923672

n�� 14�� ���,
13C1 * 48C10 - (13C2 * 44C6) + 13C3 * 40C2
= 13 * 6540715896 - 78 * 7059052 + 286 * 780
= 84478923672

n�� 16�� ���,
13C1 * 48C12 - (13C2 * 44C8) + 13C3 * 40C2
= 13 * 6540715896 - 78 * 7059052 + 286 * 780
= 84478923672

��ȭ��
13Ci * (52 - i*4)C(n - i*4) - (13C(i+1) * (52 - (i+1)*4)C(n - (i+1)*4)) + 13C(n/4) * (52 - n/4*4)C(n - n/4*4)
*/