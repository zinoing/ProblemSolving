// 15685.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

enum class Direction {
	RIGHT,
	UP,
	LEFT,
	DOWN
};

typedef pair<int,int> Pos;

bool board[101][101];

Pos getNextPos(const Direction& dir, const Pos& currPos) {
	Pos nextPos = currPos;

	switch (dir) {
	case Direction::RIGHT:
		nextPos.first += 1;
		break;
	case Direction::UP:
		nextPos.second -= 1;
		break;
	case Direction::LEFT:
		nextPos.first -= 1;
		break;
	case Direction::DOWN:
		nextPos.second += 1;
		break;
	}

	return nextPos;
}

int countSquare() {
	int cnt = 0;
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (board[i][j] == false) continue;

			if (board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) ++cnt;
		}
	}

	return cnt;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;

		vector<Pos> poses;
		vector<Direction> directions;

		Pos currPos = Pos(x, y);
		poses.push_back(currPos);

		Direction currentDir = (Direction)d;
		directions.push_back(currentDir);

		board[currPos.first][currPos.second] = true;

		Pos nextPos = getNextPos((Direction)d, currPos);
		poses.push_back(nextPos);
		board[nextPos.first][nextPos.second] = true;

		// 현재 점 2개, 방향 1개가 들어있는 상태

		for (int j = 0; j < g; ++j) {
			int size = directions.size();
			vector<Direction> temp;

			for (int k = size-1; k >= 0; --k) {
				currentDir = directions[k];

				Direction nextDir = (Direction)(((int)currentDir + 1) % 4);
				temp.push_back(nextDir);
				nextPos = getNextPos(nextDir, nextPos);
				poses.push_back(nextPos);

				board[nextPos.first][nextPos.second] = true;
			}

			// 두 벡터 합치기
			directions.insert(directions.end(), temp.begin(), temp.end());
		}
	}

	cout << countSquare();
	return 0;
}