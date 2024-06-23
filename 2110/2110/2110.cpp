// 2110.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, C;
    cin >> N >> C;

    vector<int> numbers;
    int input;
    for (int i = 0; i < N; i++) {
        cin >> input;
        numbers.push_back(input);
    }

    sort(numbers.begin(), numbers.end());

    int longestInterval = numbers.back() - numbers.front();;
    int shortestInterval = 1;
    int ans = 0;

    // 1 2 4 8 9
    while (shortestInterval <= longestInterval) {
        int mid = (longestInterval + shortestInterval) / 2;
        int previous = 0;
        int cnt = 1;

        for (int i = 1; i < N; i++) {
            if (numbers[i] - numbers[previous] >= mid) {
                ++cnt;
                previous = i;
            }
        }

        // 간격이 너무 좁을 때
        if (cnt >= C) {
            ans = max(ans, mid);
            // 간격을 늘려야 하니 shortestinterval을 늘린다.
            shortestInterval = mid + 1;
            continue;
        }

        // 간격이 너무 넓을 때
        if (cnt < C) {
            // 간격을 좁혀야 하니 longestInterval을 줄인다.
            longestInterval = mid - 1;
            continue;
        }
    }

    cout << ans;

    // 첫번째와 마지막 숫자를 더한 후 그 중간 값을 찾는다.
    // 그 후 중간값과 가장 근접한 값을 찾는다.
    /*
    int minNum = numbers.front();
    int maxNum = numbers.back();
    int avg = (minNum + maxNum) / 2;

    int left = 0;
    int right = numbers.size();
    while (left < right) {

        int mid = (left + right) / 2;

        if (numbers[mid] == avg) {
            break;
        }

        if (numbers[mid] > avg) {
            if (abs(numbers[mid] - avg) < abs(numbers[mid - 1] - avg))
                right = mid;
            else
                right = mid - 1;
            continue;
        }

        if (numbers[mid] < avg) {

            if (abs(numbers[mid] - avg) < abs(numbers[mid + 1] - avg))
                left = mid;
            else
                left = mid + 1;
            continue;
        }
    }

    int ans = min(abs(numbers.front() - numbers[left]), abs(numbers.back() - numbers[left]));

    for_each(numbers.begin(), numbers.end(), [](int a) {cout << a << ", "; });
    cout << '\n';

    cout << numbers.front() << ", " << numbers.back() << endl;
    cout << numbers[left] << ", " << numbers[right] << endl;
    cout << ans;
    */
}