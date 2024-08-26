// 모음사전.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
int cnt = 0;
bool found = false;

char changeToVowel(int vowel) {
    switch (vowel) {
    case 0:
        return 'A';
    case 1:
        return 'E';
    case 2:
        return 'I';
    case 3:
        return 'O';
    case 4:
        return 'U';
    }
}

void dfs(int depth, string word, string wordToFind) {
    if (!found) {
        ++cnt;
    }
    else return;

    if (depth == 5) {
        return;
    }

    for (int i = 0; i < 5; i++) {
        string str = word + changeToVowel(i);

        /*if (wordToFind == str) {
            found = true;
            return;
        }*/
        cout << cnt << ": " << str << '\n';
        dfs(depth + 1, str, wordToFind);
    }
}

int solution(string word) {

    dfs(0, "", word);

    int answer = cnt;
    return answer;
}

int main()
{
    string str = "AAAAE";
    cout << solution(str);

    return 0;
}