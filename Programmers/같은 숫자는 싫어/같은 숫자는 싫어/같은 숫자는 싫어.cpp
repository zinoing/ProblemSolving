// 같은 숫자는 싫어.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    int previous = -1;

    for (int number : arr) {
        if (number != previous) {
            answer.push_back(number);
            previous = number;
        }
    }

    return answer;
}
int main()
{
    std::cout << "Hello World!\n";
}