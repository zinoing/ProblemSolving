// 베스트앨범.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    int n = genres.size();

    // 입력 값 받기
    unordered_map<string, vector<pair<int, int>>> genre_play_idx_map;
    for (int i = 0; i < n; ++i) {
        genre_play_idx_map[genres[i]].push_back(make_pair(plays[i], i));
    }

    // 장르별 합 구하기
    unordered_map<int, string> genre_sum_map;
    vector<int> sum_rank;
    for (auto map : genre_play_idx_map) {
        vector<pair<int, int>> vec = map.second;
        int sum = 0;
        for (auto pair : vec) {
            sum += pair.first;
        }
        sum_rank.push_back(sum);
        genre_sum_map[sum] = map.first;
    }

    sort(sum_rank.begin(), sum_rank.end(), greater<int>());

    vector<int> answer;
    for (int sum : sum_rank) {
        string genre = genre_sum_map[sum];
        vector<pair<int, int>> vec = genre_play_idx_map[genre];

        sort(vec.begin(), vec.end(), comp);

        if (vec.size() == 1) {
            answer.push_back(vec[0].second);
        }
        else {
            // 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록
            if (vec[0].first == vec[1].first) {
                int min_idx = min(vec[0].second, vec[1].second);
                int max_idx = max(vec[0].second, vec[1].second);

                answer.push_back(min_idx);
                answer.push_back(max_idx);
            }
            else {
                answer.push_back(vec[0].second);
                answer.push_back(vec[1].second);
            }
        }
    }

    return answer;
}