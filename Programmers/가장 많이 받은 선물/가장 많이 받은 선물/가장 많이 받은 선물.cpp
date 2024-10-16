// 가장 많이 받은 선물.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    unordered_map<string, unordered_map<string, int>> gift_map;
    unordered_map<string, int> gift_idx_map;

    for (auto gift : gifts) {
        istringstream iss(gift);
        string giver;
        string receiver;
        iss >> giver >> receiver;

        // receiver한테 얼만큼 줬는지 기록
        unordered_map<string, int> giver_map = gift_map[giver];
        giver_map[receiver] += 1;
        gift_map[giver] = giver_map;

        gift_idx_map[giver] += 1;
        gift_idx_map[receiver] -= 1;
    }

    unordered_map<string, int> planned_gift_map;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue; // 자신은 제외

            // 서로 각자 얼마나 줬는지 확인
            int iToj = gift_map[friends[i]][friends[j]];
            int jToi = gift_map[friends[j]][friends[i]];
            //cout << i << "->" << j << " : " << iToj << endl;
            //cout << j << "->" << i << " : " << jToi << endl;
            // i가 더 많이 주었다면
            if (iToj > jToi) {
                planned_gift_map[friends[i]] += 1;
            }
            // j가 더 많이 주었다면
            else if (iToj < jToi) {
                planned_gift_map[friends[j]] += 1;
            }
            // 두 사람이 선물을 주고받은 기록이 하나도 없거나 주고받은 수가 같다면
            else {
                int i_idx = gift_idx_map[friends[i]];
                int j_idx = gift_idx_map[friends[j]];

                if (i_idx > j_idx) {
                    planned_gift_map[friends[i]] += 1;
                }
                else if (i_idx < j_idx) {
                    planned_gift_map[friends[j]] += 1;
                }
                else {
                    // 만약 두 사람의 선물 지수도 같다면 다음 달에 선물을 주고받지 않는다
                }
            }
        }
    }
    int max = 0;
    for (auto plan : planned_gift_map) {
        if (planned_gift_map[plan.first] > max) {
            max = planned_gift_map[plan.first];
        }
    }

    int answer = max / 2;
    return answer;
}