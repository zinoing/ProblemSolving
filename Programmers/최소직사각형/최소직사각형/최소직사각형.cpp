// 최소직사각형.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxHeight = 0;
    int maxWidth = 0;
    int maxSize = 0;

    for (int i = 0; i < sizes.size(); i++) {
        if (sizes[i][0] > sizes[i][1]) {
            maxHeight = max(maxHeight, sizes[i][0]);
            maxWidth = max(maxWidth, sizes[i][1]);
        }
        else {
            maxHeight = max(maxHeight, sizes[i][1]);
            maxWidth = max(maxWidth, sizes[i][0]);
        }
    }
    maxSize = maxHeight * maxWidth;
    int answer = maxSize;
    return answer;
}

int main()
{
    vector<vector<int>> sizes;
    vector<int> vec;
    vec.push_back(60);
    vec.push_back(50);
    sizes.push_back(vec);
    vec.clear();

    vec.push_back(30);
    vec.push_back(70);
    sizes.push_back(vec);
    vec.clear();

    vec.push_back(60);
    vec.push_back(30);
    sizes.push_back(vec);
    vec.clear();

    vec.push_back(80);
    vec.push_back(40);
    sizes.push_back(vec);

    cout << solution(sizes);
}