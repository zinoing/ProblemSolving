// 5568.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, k;
set<string> s;
vector<string> v;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    string input;
    for (int i = 0; i < n; i++) {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    do {
        string str;
        for (int i = 0; i < k; i++) {
            str += v[i];
        }
        s.insert(str);
    } while (next_permutation(v.begin(), v.end()));

    cout << s.size() << endl;
}