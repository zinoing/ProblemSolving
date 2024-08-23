// 26006.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numOfMovablePlace;

struct MovablePlace {
    bool canGo;
    pair<int, int> coord;

    MovablePlace(pair<int, int> coord) {
        canGo = true;
        this->coord = coord;
    }
};

int N, K;
pair<int, int> whiteKing;
MovablePlace* center;
vector<MovablePlace> whiteKingPlace;
vector<pair<int, int>> blackQueens;

void checkState() {
    int cnt = 0;

    for (int i = 0; i < numOfMovablePlace; i++) {
        if (whiteKingPlace[i].coord == whiteKing) {
            center = &whiteKingPlace[i];
            break;
        }
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < numOfMovablePlace; j++) {
            // 행이 겹치는지 확인
            if (blackQueens[i].first == whiteKingPlace[j].coord.first && whiteKingPlace[j].canGo) {
                whiteKingPlace[j].canGo = false;
                ++cnt;
                continue;
            }
            // 열이 겹치는지 확인
            if (blackQueens[i].second == whiteKingPlace[j].coord.second && whiteKingPlace[j].canGo) {
                whiteKingPlace[j].canGo = false;
                ++cnt;
                continue;
            }
            // 대각선이 겹치는지 확인
            if (whiteKingPlace[j].coord.first + whiteKingPlace[j].coord.second == blackQueens[i].first + blackQueens[i].second && whiteKingPlace[j].canGo) {
                whiteKingPlace[j].canGo = false;
                ++cnt;
                continue;
            }

            if (whiteKingPlace[j].coord.first - whiteKingPlace[j].coord.second == blackQueens[i].first - blackQueens[i].second && whiteKingPlace[j].canGo) {
                whiteKingPlace[j].canGo = false;
                ++cnt;
                continue;
            }
        }
    }

    if (cnt == numOfMovablePlace) {
        cout << "CHECKMATE";
        return;
    }

    if (cnt == numOfMovablePlace-1 && center->canGo) {
        cout << "STALEMATE";
        return;
    }

    if (!center->canGo) {
        cout << "CHECK";
        return;
    }

    cout << "NONE";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> K;

    int R, C;
    cin >> R >> C;
    whiteKing = make_pair(C, R);

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (whiteKing.first + i > N || whiteKing.first + i < 1 || whiteKing.second + j > N || whiteKing.second + j < 1)
                continue;

            ++numOfMovablePlace;
            MovablePlace place = MovablePlace(make_pair(whiteKing.first + i, whiteKing.second + j));
            whiteKingPlace.push_back(place);
        }
    }

    for (int i = 0; i < K; i++) {
        cin >> R >> C;
        blackQueens.push_back(make_pair(C, R));
    }

    checkState();

    return 0;
}
