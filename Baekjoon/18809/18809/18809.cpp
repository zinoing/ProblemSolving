// 18809.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

#define LAKE 0
#define CANT_SPRINKLE 1
#define CAN_SPRINKLE 2
#define RED 3
#define GREEN 4
#define FLOWER 5

typedef pair<int, int> Pos;
typedef pair<Pos, int> Sprinkle_Info; // 위치, 색

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int N, M, G, R;
vector<vector<int>> originGarden(51, vector<int>(51));
vector<vector<int>> copiedGarden(51, vector<int>(51));
vector<vector<int>> visited(51, vector<int>(51));
vector<vector<int>> copiedVisited(51, vector<int>(51));
vector<Sprinkle_Info> sprinkles;

int numOfCanSprinkle = 0;
int maxFlowers = 0;

void getInput() {
	cin >> N >> M >> G >> R;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> originGarden[i][j];

			visited[i][j] = false;

			if (originGarden[i][j] == CAN_SPRINKLE) {
				sprinkles.push_back(make_pair(Pos(i, j), CAN_SPRINKLE));
				++numOfCanSprinkle;
			}

			if (originGarden[i][j] == LAKE) {
				visited[i][j] = true;
			}
		}
	}
}

bool checkOutOfRange(int y, int x, int color) {
	if (y >= N || y < 0 || x >= M || x < 0) {
		return true;
	}

	// 같은 색이거나, 꽃이거나, 호수일 경우
	if (copiedGarden[y][x] == color) return true;
	if (copiedGarden[y][x] == FLOWER) return true;
	if (copiedGarden[y][x] == LAKE) return true;

	return false;
}

int spread(Pos pos, int color, vector<Sprinkle_Info>& newSpread) {
	int flowerCnt = 0;
	bool bloom = false;
	bool sameColor = true;

	for (int i = 0; i < 4; ++i) {
		int dirY = pos.first + dy[i];
		int dirX = pos.second + dx[i];

		if (checkOutOfRange(dirY, dirX, color)) continue;

		for (auto spread : newSpread) {
			// 새롭게 퍼진 배양액과 위치가 같은 경우
			if (dirY == spread.first.first && dirX == spread.first.second) {
				// 색이 다른 경우
				if (color != spread.second) {
					copiedGarden[dirY][dirX] = FLOWER;
					++flowerCnt;
					bloom = true;
					sameColor = false;
					newSpread.erase(remove(newSpread.begin(), newSpread.end(), spread), newSpread.end());
				}
				break;
			}
		}

		// 새롭게 퍼진 배양액과 겹치지만 같은 색인 경우
		// 꽃이 피지 않았다면
		if (!bloom && !copiedVisited[dirY][dirX]) {
			copiedGarden[dirY][dirX] = color;
			copiedVisited[dirY][dirX] = true;
			newSpread.push_back(Sprinkle_Info(Pos(dirY, dirX), color));
		}

		bloom = false;
		sameColor = true;
	}

	return flowerCnt;
}

void solve(vector<Sprinkle_Info> permutation) {
	copiedGarden = originGarden;
	copiedVisited = visited;

	vector<Sprinkle_Info> newSpread;
	int flowerCnt = 0;

	for (int i = 0; i < permutation.size(); ++i) {
		copiedGarden[permutation[i].first.first][permutation[i].first.second] = permutation[i].second;
		copiedVisited[permutation[i].first.first][permutation[i].first.second] = true;
		flowerCnt += spread(permutation[i].first, permutation[i].second, newSpread);
	}

	while (!newSpread.empty()) {
		permutation = newSpread;
		newSpread.clear();

		for (int i = 0; i < permutation.size(); ++i) {
			copiedGarden[permutation[i].first.first][permutation[i].first.second] = permutation[i].second;
			copiedVisited[permutation[i].first.first][permutation[i].first.second] = true;
			flowerCnt += spread(permutation[i].first, permutation[i].second, newSpread);

			//cout << endl;
			//for (int i = 0; i < N; ++i) {
			//	for (int j = 0; j < M; ++j) {
			//		cout << copiedGarden[i][j] << " ";
			//	}
			//	cout << endl;
			//}
		}
	}

	maxFlowers = max(flowerCnt, maxFlowers);

	return;
}

// 순열 생성과 백트래킹 기능 구현
void dfs(int idx, vector<Sprinkle_Info> permutation) {

	if (idx == numOfCanSprinkle) {
		if (G > 0 || R > 0) return;
		solve(permutation);
		return;
	}

	if (G > 0) {
		// 초록색 변환
		sprinkles[idx].second = GREEN;
		permutation.push_back(sprinkles[idx]);
		visited[sprinkles[idx].first.first][sprinkles[idx].first.second] = true;
		--G;
		dfs(idx + 1, permutation);
		++G;
		visited[sprinkles[idx].first.first][sprinkles[idx].first.second] = false;
		permutation.pop_back();
		sprinkles[idx].second = CAN_SPRINKLE;
	}

	if (R > 0) {
		// 붉은색 변환
		sprinkles[idx].second = RED;
		permutation.push_back(sprinkles[idx]);
		visited[sprinkles[idx].first.first][sprinkles[idx].first.second] = true;
		--R;
		dfs(idx + 1, permutation);
		++R;
		visited[sprinkles[idx].first.first][sprinkles[idx].first.second] = false;
		permutation.pop_back();
		sprinkles[idx].second = CAN_SPRINKLE;
	}

	// 색 변환을 하지 않고 넘어가기
	dfs(idx + 1, permutation);

	return;
}

int main() {
	getInput();

	vector<Sprinkle_Info> permutation;
	dfs(0, permutation);

	cout << maxFlowers;
	return 0;
}