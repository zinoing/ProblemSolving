// 13277.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> strToVec(string str) {
    vector<int> vec;

    int i = str.size()-1;
    while (i >= 0) {
        vec.push_back(str[i] - '0');
        --i;
    }

    return vec;
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    int an = a.size();
    int bn = b.size();
    vector<int> result(an + bn, 0);

    for (int i = 0; i < an; ++i) {
        for (int j = 0; j < bn; ++j) {
            int product = a[i] * b[j];
            result[i + j] += product;
            if (result[i + j] >= 10) {
                result[i + j + 1] += result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
    int carry = 0;
    int n = max(a.size(), b.size() + k);
    a.resize(n, 0); // a를 n으로 크기 조정하고 초기화

    for (int i = 0; i < n; ++i) {
        int numA = (i < a.size()) ? a[i] : 0; // a의 현재 자리
        int numB = (i - k >= 0 && i - k < b.size()) ? b[i - k] : 0; // k만큼 이동한 b의 현재 자리
        int sum = numA + numB + carry;
        a[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        a.push_back(carry);
    }
}

void subFrom(vector<int>& a, const vector<int>& b) {
    int n = b.size();

    for (int i = 0; i < n; ++i) {
        int num = a[i] - b[i];
        if (num < 0) {
            a[i] += 10;
            a[i + 1] -= 1;
        }
        a[i] += num;
    }

    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}
/*
a + b = (a0 + a1) * (b0 + b1)
      = (a0 * b0) + (a0 * b1 + a1 * b0) + (a1 * b1)
      = z0 + z1 + z2

z1 = (a * b - z0 - z2)
*/

vector<int> karatsuba(vector<int> A, vector<int> B) {
    if (A.size() == 0 || B.size() == 0) return vector<int>();

    if (A.size() < B.size()) return karatsuba(B, A);

    if (A.size() <= 50) return multiply(A, B);

    int half = A.size() / 2;

    vector<int> a0(A.begin(), A.begin() + half);
    vector<int> a1(A.begin() + half, A.end());

    vector<int> b0(B.begin(), B.begin() + half);
    vector<int> b1(B.begin() + half, B.end());

    vector<int> z0 = multiply(a0, b0);
    vector<int> z2 = multiply(a1, b1);

    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);

    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    // 불필요한 0 제거
    while (ret.size() > 1 && ret.back() == 0) {
        ret.pop_back();
    }

    return ret;
}

int main()
{
    string A, B;
    cin >> A >> B;

    vector<int> vec =  karatsuba(strToVec(A), strToVec(B));

    for (int i = vec.size() - 1; i >= 0; --i) {
        cout << vec[i];
    }
}