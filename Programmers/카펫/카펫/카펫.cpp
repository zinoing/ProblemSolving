// 카펫.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int total = brown + yellow;
    for (int i = 1; i <= total; i++) {
        if (total % i != 0) continue;
        int height = i;
        int width = total / i;

        if (2 * (height + width) - 4 == brown) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }

    return answer;
}