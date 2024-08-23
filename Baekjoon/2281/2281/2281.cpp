// 2281.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

#define INT_MAX 2147483646
using namespace std;

int getSum(deque<int> dq) {
    int sum = 0;
    for (int i = 0; i < dq.size(); i++) {
        if (i == 0) {
            sum += dq[i];
        }
        else {
            sum += (dq[i] + 1);
        }
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    vector<int> names;
    cin >> n >> m;

    int name;
    for (int i = 0; i < n; i++) {
        cin >> name;
        names.push_back(name);
    }

    int index = 0;
    int lineIndex = 0;
    deque<int> line[1001];
    int sum = INT_MAX;
    int minSum = 0;


    while(index < n) {
        int firstLineSum = 0;
        int secondLineSum = 0;

        // 이름을 넣어도 첫 번째 라인을 넘지 않는 경우
        while (index < n && getSum(line[lineIndex]) + names[index] <= m) {
            line[lineIndex].push_back(names[index]);
            ++index;
        }

        // 이름을 넣어도 두 번째 라인을 넘지 않는 경우
        while (index < n && getSum(line[lineIndex + 1]) + names[index] <= m) {
            line[lineIndex + 1].push_back(names[index]);
            ++index;
        }

        // 남은 칸 제곱의 합 계산
        if (sum > pow(m - getSum(line[lineIndex]), 2) + pow(m - getSum(line[lineIndex + 1]), 2)) {

            firstLineSum = getSum(line[lineIndex]);
            secondLineSum = getSum(line[lineIndex + 1]);

            sum = pow(m - getSum(line[lineIndex]), 2) + pow(m - getSum(line[lineIndex + 1]), 2);
        }

        // firstLine의 마지막 이름이 secondLine에 들어갈 수 있는지 확인
        int firstLineLastName = line[lineIndex].back();
        if (getSum(line[lineIndex + 1]) + firstLineLastName + 1 <= m) {
            // 남은 칸 제곱의 합 계산
            if (sum > pow(m - (getSum(line[lineIndex]) - firstLineLastName - 1), 2) + pow(m - (getSum(line[lineIndex]) + firstLineLastName + 1), 2)) {
                sum = pow(m - (getSum(line[lineIndex]) - firstLineLastName - 1), 2) + pow(m - (getSum(line[lineIndex]) + firstLineLastName + 1), 2);

                firstLineSum = getSum(line[lineIndex]) - firstLineLastName - 1;
                secondLineSum = getSum(line[lineIndex]) + firstLineLastName + 1;

                line[lineIndex].pop_back();
                line[lineIndex + 1].push_front(firstLineLastName);
            }
        }
        // 불가능할 경우
        else {
            // 마지막 이름 제거 후 가능 여부 판단
            int secondLineLastName = line[lineIndex + 1].back();
            // 가능
            if (getSum(line[lineIndex + 1]) + firstLineLastName - secondLineLastName <= m) {
                // 남은 칸 제곱의 합 계산
                if (sum > pow(m - (getSum(line[lineIndex]) - firstLineLastName - 1), 2) + pow(m - (getSum(line[lineIndex + 1]) + firstLineLastName - secondLineLastName), 2)) {
                    sum = pow(m - (getSum(line[lineIndex]) - firstLineLastName - 1), 2) + pow(m - (getSum(line[lineIndex + 1]) + firstLineLastName - secondLineLastName), 2);

                    firstLineSum = getSum(line[lineIndex]) - firstLineLastName - 1;
                    secondLineSum = getSum(line[lineIndex + 1]) + firstLineLastName - secondLineLastName;

                    line[lineIndex].pop_back();
                    line[lineIndex + 1].pop_back();
                    line[lineIndex + 1].push_front(firstLineLastName);
                    --index;
                }
            }
        }
        
        if (index < n) {
            minSum += pow(m - firstLineSum, 2);
        }
        ++lineIndex;
        sum = INT_MAX;
    }

    cout << minSum;
}
