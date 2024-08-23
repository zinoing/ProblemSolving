// 10451.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

int count(int* arr, int size) {
    int cnt = 0;
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == -1)
            continue;

        index = i;
        while (index != size) {
            if (arr[index] == -1) {
                ++cnt;
                break;
            }
            int temp = arr[index] - 1;
            arr[index] = -1;
            index = temp;
        }
    }

    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int N;
    int* arr;
    for (int i = 0; i < T; i++) {
        cin >> N;
        arr = new int[N];
        int input;
        for (int j = 0; j < N; j++) {
            cin >> input;
            arr[j] = input;
        }
        cout << count(arr, N) << '\n';
        delete arr;
        arr = nullptr;
    }
}
