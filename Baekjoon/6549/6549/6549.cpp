// 6549.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

using namespace std;

long long findTheLargestRectangle(const vector<int>& lengths, int start, int end) {

    if (start == end) return lengths[start];

    int mid = (start + end) / 2;

    long long leftRectangle = findTheLargestRectangle(lengths, start, mid);
    long long rightRectangle = findTheLargestRectangle(lengths, mid + 1, end);
    long long maxRectangle = max(leftRectangle, rightRectangle);

    int minHeight = min(lengths[mid], lengths[mid + 1]);
    long long midRectangle = 2 * minHeight;
    maxRectangle = max(midRectangle, maxRectangle);
    int left = mid - 1;
    int right = mid + 2;

    while (1) {
        // 더 이상 진행할 곳이 없을 경우
        if (left < start && right > end) break;

        long long temp = 0;
        if (left < start) {
            minHeight = min(minHeight, lengths[right]);
            temp = (long long)(right - start + 1) * minHeight;
            ++right;
            midRectangle = max(midRectangle, temp);
            maxRectangle = max(midRectangle, maxRectangle);
            continue;
        }

        if (right > end) {
            minHeight = min(minHeight, lengths[left]);
            temp = (long long)(end - left + 1) * minHeight;
            --left;
            midRectangle = max(midRectangle, temp);
            maxRectangle = max(midRectangle, maxRectangle);
            continue;
        }

        if (lengths[left] > lengths[right]) {
            minHeight = min(minHeight, lengths[left]);
            temp = (long long)(right - left) * minHeight;
            --left;
        }
        else {
            minHeight = min(minHeight, lengths[right]);
            temp = (long long)(right - left) * minHeight;
            ++right;
        }

        midRectangle = max(midRectangle, temp);
        maxRectangle = max(midRectangle, maxRectangle);
    }

    //cout << "start: " << start << " end: " << end << " maxRectangle: " << maxRectangle << endl;
    return maxRectangle;
}

int main()
{
    int N;
    while (1) {
        cin >> N;

        if (N == 0) break;

        vector<int> lengths(N, 0);
        for (int i = 0; i < N; ++i) {
            int input;
            cin >> input;

            lengths[i] = input;
        }

        cout << findTheLargestRectangle(lengths, 0, N-1) << endl;
    }
}

/*
5 1000000000 1000000000 1000000000 1000000000 1000000000 => 5000000000
8 1 2 3 4 5 6 7 8 => 20
7 8 7 1 1 1 9 6 => 14
*/