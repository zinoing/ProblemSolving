// 주식가격.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for (int i = 0; i < prices.size(); i++) {
        int cnt = 0;
        for (int j = i; j < prices.size(); j++) {
            if (prices[i] > prices[j]) {
                answer.push_back(cnt);
                break;
            }

            if (j == prices.size() - 1) answer.push_back(cnt);
            ++cnt;
        }
    }
    return answer;
}