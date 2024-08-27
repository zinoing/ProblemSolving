// 올바른 괄호.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> stackChar;

bool solution(string s)
{
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stackChar.push(s[i]);
        }
        else {
            if (!stackChar.empty()) {
                stackChar.pop();
            }
            else return false;
        }
    }

    bool answer = (stackChar.size() == 0) ? true : false;

    return answer;
}
int main()
{
    string str = "())";
    std::cout << solution(str);
}