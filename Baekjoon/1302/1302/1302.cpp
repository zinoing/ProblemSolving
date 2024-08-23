// 1302.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int N;
map<string, int, greater<>> m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max = -1;
    string nameOfBestSeller = "z";

    cin >> N;
    string nameOfBook;
    for (int i = 0; i < N; i++) {
        cin >> nameOfBook;

        auto it = m.find(nameOfBook);
        if (it == m.end()) {
            // 찾는 것이 없다면 초기화
            m.insert(make_pair(nameOfBook, 1));

            // 첫 입력이라면 베트스트셀러 초기화
            if (max == -1) {
                nameOfBestSeller = nameOfBook;
                max = 1;
            }
            else {
                if (max == 1 && nameOfBestSeller > nameOfBook) {
                    nameOfBestSeller = nameOfBook;
                    max = 1;
                }
            }
            continue;
        }

        ++it->second;

        if (it->second > max) {
            nameOfBestSeller = it->first;
            max = it->second;
            continue;
        }

        if (it->second == max && nameOfBestSeller > it->first) {
            nameOfBestSeller = it->first;
            max = it->second;
        }
    }

    cout << nameOfBestSeller << endl;

    //for (auto& it : m) {
    //    cout << it.first << ", " << it.second << endl;
    //}
}