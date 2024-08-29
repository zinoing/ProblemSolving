// 다리를 지나는 트럭.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> trucks_on_bridge;
    int day = 0;

    int frontTruck = 0;
    int truck_weights_on_bridge = 0;

    while (1) {
        // 다리 위의 트럭이 다리를 지날 수 있는지 확인하기
        if (!trucks_on_bridge.empty()) {
            pair<int, int> front_truck_on_bridge = trucks_on_bridge.front();

            while (day - front_truck_on_bridge.second == bridge_length) {
                trucks_on_bridge.pop();
                truck_weights_on_bridge -= front_truck_on_bridge.first;

                front_truck_on_bridge = trucks_on_bridge.front();
            }
        }

        // 트럭이 다리 위에 올라갈 수 있다면
        if (frontTruck < truck_weights.size() &&
            truck_weights_on_bridge + truck_weights[frontTruck] <= weight &&
            trucks_on_bridge.size() + 1 <= bridge_length) {
            trucks_on_bridge.push(make_pair(truck_weights[frontTruck], day));
            truck_weights_on_bridge += truck_weights[frontTruck];
            ++frontTruck;
        }

        ++day;

        if (frontTruck >= truck_weights.size() && trucks_on_bridge.empty()) break;
    }

    int answer = day;
    return answer;
}