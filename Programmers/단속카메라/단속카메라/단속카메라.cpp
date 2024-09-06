// 단속카메라.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> routesPQ;

    for (int i = 0; i < routes.size(); i++) {
        routesPQ.push(make_pair(routes[i][0], routes[i][1]));
    }

    int answer = 0;
    vector<pair<int, int>> CCTVs;
    pair<int, int> interval = make_pair(-30001, -30001);
    for (int i = 0; i < routes.size(); i++) {
        pair<int, int> route = routesPQ.top();
        cout << route.first << ' ' << route.second << '\n';
        routesPQ.pop();
        if (route.first <= interval.second) {
            bool needCCTV = true;
            for (pair<int, int> cctv : CCTVs) {
                if (cctv.first >= route.first && cctv.first <= route.second) {
                    needCCTV = false;
                    break;
                }

            }
            if (needCCTV)
                interval = make_pair(route.first, min(interval.second, route.second));
        }
        else {
            // 이전의 카메라 범위를 담아둔다.
            CCTVs.push_back(interval);
            interval = route;
            ++answer;
        }
    }
    return answer;
}