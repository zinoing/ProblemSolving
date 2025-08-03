// priority_queue_test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>

using namespace std;

// 구조체 정의
struct Task {
    int start;
    int end;
    int value;
};

// 비교 연산자 정의
bool operator<(const Task& t, const Task& u) {
    return t.value < u.value;  // 큰 값이 우선순위가 높아지도록
}

// 사용자 정의 비교 함수 객체를 사용한 priority_queue
struct Compare {
    bool operator()(const Task& t, const Task& u) {
        return t.value < u.value;  // 큰 값이 우선순위가 높아지도록
    }
};

int main() {
    // 비교 연산자를 사용하여 priority_queue 생성
    priority_queue<Task, vector<Task>, Compare> pq;

    // 테스트 데이터 추가
    pq.push({ 1, 5, 10 });
    pq.push({ 2, 6, 20 });
    pq.push({ 3, 7, 15 });

    // 우선순위 큐에서 요소를 출력
    while (!pq.empty()) {
        Task t = pq.top();
        cout << "Start: " << t.start << ", End: " << t.end << ", Value: " << t.value << endl;
        pq.pop();
    }

    return 0;
}