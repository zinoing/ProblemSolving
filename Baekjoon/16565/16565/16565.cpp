// 16565.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define TOTAL_CARDS 52
#define MOD         10007

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
점화식
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
    // 4장 미만으로 뽑을 시 four of a kind를 완성 시킬 수 없다.
    if (n < 4) return 0;

    // 4장을 뽑을 시 13가지의 four of a kind를 완성 시킬 수 있다.
    if (n == 4) return 13;

    long long outcomes = 0;

    for (int i = 1; i <= n / 4; ++i) {
        long long comb1 = numberOfCombinations(13, i);
        long long comb2 = numberOfCombinations(TOTAL_CARDS - 4 * i, n - 4 * i);

        if (i % 2 == 0) {
            outcomes = (outcomes - comb1 * comb2) % MOD; // 짝수인 경우 빼기
        }
        else {
            outcomes = (outcomes + comb1 * comb2) % MOD; // 홀수인 경우 더하기
        }
    }

    return (outcomes + MOD) % MOD;  // 음수 처리
}

int main()
{
    int n;
    cin >> n;

    cout << solve(n);
}

/*
n이 5인 경우,
13 * (52 - 4) = 624

n이 6인 경우,
13 * (52 - 4) * (52 - 5) / 2! = 14664

n이 7인 경우, 
13 * (52 - 4) * (52 - 5) * (52 - 6) / 3! = 224848

n이 8인 경우,
13 * (52 - 4) * (52 - 5) * (52 - 6) * (52 - 7) / 4! = 2529540
위와 같이 풀면 틀림, why => 8장 카드 중 4,4로 포카드 두개의 경우가 겹치는 경우 발생 따라서 이를 제외해주어야 한다.
13개의 숫자 종류 중에 2개를 뽑는 경우의 수 13C2 = 13 * 6 = 78
2529540 - 78 = 2529462

n이 12인 경우,
13C1 * 48C8 - (13C2 * 44C4) + 13C3
= 13 * 377348994 - 78 * 135751 + 286
= 4894948630

n이 20인 경우,
13C1 * 48C16 - (13C2 * 44C6) + 13C3 * 40C2
= 13 * 6540715896 - 78 * 7059052 + 286 * 780
= 84478923672

n이 14인 경우,
13C1 * 48C10 - (13C2 * 44C6) + 13C3 * 40C2
= 13 * 6540715896 - 78 * 7059052 + 286 * 780
= 84478923672

n이 16인 경우,
13C1 * 48C12 - (13C2 * 44C8) + 13C3 * 40C2
= 13 * 6540715896 - 78 * 7059052 + 286 * 780
= 84478923672

점화식
13Ci * (52 - i*4)C(n - i*4) - (13C(i+1) * (52 - (i+1)*4)C(n - (i+1)*4)) + 13C(n/4) * (52 - n/4*4)C(n - n/4*4)
*/