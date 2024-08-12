// 2644.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int numOfPeople;
int person1, person2;
int numOfRelationships;
vector<int> family[101];
bool visited[101];

int dfs(int person, int depth) {
    int size = family[person].size();

    for (int i = 0; i < size; i++) {
        int relatedPerson = family[person][i];
        if (relatedPerson == person) continue;
        if (relatedPerson == person1) continue;
        if (visited[relatedPerson]) continue;

        if (relatedPerson == person2) {
            return depth;
        }

        visited[relatedPerson] = true;
        int result = dfs(relatedPerson, depth + 1);
        if (result != -1) return result;
        visited[relatedPerson] = false;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> numOfPeople;
    cin >> person1 >> person2;
    cin >> numOfRelationships;

    for (int i = 0; i < numOfRelationships; i++) {
        int parent, child;
        cin >> parent >> child;
        family[parent].push_back(child);
        family[child].push_back(parent);
    }

    cout << dfs(person1, 1);
}