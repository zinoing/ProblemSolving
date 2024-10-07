#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size(), bn = b.size();

    if (an < bn) return karatsuba(b, a);
    if (an == 0 || bn == 0) return vector<int>();
    if (an <= 50) return multiply(a, b);

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

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

int main() {
    int length = 100;

    vector<int> a(length, 0);
    vector<int> b(length, 0);

    a[length - 1] = b[length - 1] = 1;
    for (int i = 0; i < length - 1; ++i) {
        a[i] = rand() % 10;
        b[i] = rand() % 10;
    }

    cout << "a: ";
    for (int i = length - 1; i >= 0; --i) {
        cout << a[i];
    }
    cout << endl;

    cout << "b: ";
    for (int i = length - 1; i >= 0; --i) {
        cout << b[i];
    }
    cout << endl;

    vector<int> answer = karatsuba(a, b);

    cout << "Result: ";
    for (int i = answer.size() - 1; i >= 0; --i) {
        cout << answer[i];
    }
    cout << endl;
}