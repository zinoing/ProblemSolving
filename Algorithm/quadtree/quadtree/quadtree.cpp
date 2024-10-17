// quadtree.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>

#define MAX_SIZE 16

using namespace std;

char decompressed[MAX_SIZE][MAX_SIZE];

void decompress(string::iterator& it, int y, int x, int size) {
    // 한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮긴다.
    char head = *(it++);
    // 기저 사례: 첫 글자가 b 또는 w인 경우
    if (head == 'b' || head == 'w') {
        for (int dy = 0; dy < size; ++dy) {
            for (int dx = 0; dx < size; ++dx) {
                decompressed[y + dy][x + dx] = head;
            }
        }
    }
    else {
        int half = size / 2;
        decompress(it, y, x, half);
        decompress(it, y, x + half, half);
        decompress(it, y + half, x, half);
        decompress(it, y + half, x + half, half);
    }
}

// 더 효율적인 방식
string reverse(string::iterator& it) {
    char head = *it;
    ++it;
    if (head == 'b' || head == 'w')
        return string(1, head);
    string upperLeft = reverse(it);
    string upperRight = reverse(it);
    string lowerLeft = reverse(it);
    string lowerRight = reverse(it);

    return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main()
{
    string tree = "xxwwwbxwxwbbbwwxxxwwbbbwwwwbb"; // => xbxbwwxwwbwbbwwxwwxbbbwwxbwww
    string::iterator it = tree.begin();
    //decompress(it, 0, 0, MAX_SIZE);
    cout << reverse(it) << endl;

    for (int i = 0; i < MAX_SIZE; ++i) {
        for (int j = 0; j < MAX_SIZE; ++j) {
            cout << decompressed[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

// https://www.acmicpc.net/problem/1992
// https://algospot.com/judge/problem/read/QUADTREE