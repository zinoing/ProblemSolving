// H-Index.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {

    sort(citations.begin(), citations.end());
    int answer = 0;

    for (int h = 0; h <= citations.size(); h++) {
        int cnt = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h) {
                cnt = citations.size() - i;
                break;
            }
        }

        if (h > cnt) continue;
        else {
            answer = max(answer, h);
        }
    }

    return answer;
}
int main()
{
    vector<int> citations = { 3, 4 };
    cout << solution(citations);
}