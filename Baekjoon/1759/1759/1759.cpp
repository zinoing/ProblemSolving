// 1759.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> chars;
bool visited[26];
int arr[16];

void dfs(int depth) {
    if (depth == L) {
        //최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음이 존재하는지 확인
        int vowelCnt = 0;
        int consonantCnt = 0;
        for (int i = 0; i < L; i++) {
            char c = (char)(arr[i] + 'a');
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                ++vowelCnt;
            }
            else {
                ++consonantCnt;
            }
        }

        if (vowelCnt == 0 || consonantCnt < 2)
            return;

        for (int i = 0; i < L; i++) {
            cout << (char)(arr[i] + 'a');
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < C; i++) {
        int character = (int)chars[i] - 'a';
        if (!visited[character]) {
            if (depth >= 1 && arr[depth - 1] > character)
                continue;
            visited[character] = true;
            arr[depth] = character;
            dfs(depth + 1);
            visited[character] = false;
            arr[depth] = 0;
        }
    }
}

int main()
{
    cin >> L >> C;
    char c;
    for (int i = 0; i < C; i++) {
        cin >> c;
        chars.push_back(c);
    }
    
    sort(chars.begin(), chars.end());

    dfs(0);
}