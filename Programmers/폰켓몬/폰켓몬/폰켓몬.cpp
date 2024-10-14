// 폰켓몬.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    sort(nums.begin(), nums.end());

    set<int> typesOfPokemon;

    for (auto pokemon : nums) {
        typesOfPokemon.insert(pokemon);
    }

    int n = nums.size();
    int numOfTypes = typesOfPokemon.size();
    int answer = n / 2 > numOfTypes ? numOfTypes : n / 2;
    return answer;
}