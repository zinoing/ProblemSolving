#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class Computers {
    vector<list<pair<int, int>>> computers;
    
public:
    void Push(pair<int, int> time) {
        // check if there is any computer that can use
        for (int i = 0; i < computers.size(); i++) {

            auto it = computers[i].begin();
            if (time.second <= it->first) {
                computers[i].insert(it, time);
                return;
            }

            if (time.first >= computers[i].back().second) {
                computers[i].push_back(time);
                return;
            }

            if (computers[i].size() == 1) {
                continue;
            }

            for (int j = 0; j < computers[i].size() - 1; j++) {
                auto first = std::next(it, j);
                auto second = std::next(it, j+1);

                if (time.first <= first->second && time.second <= second->first) {
                    computers[i].insert(first, time);
                    return;
                }
            }
        }

        // if there isn't any computers to use make new one
        list<pair<int, int>> list;
        list.push_back(time);
        computers.push_back(list);
    }

    void Print() {
        cout << computers.size() << '\n';
        for (int i = 0; i < computers.size(); i++) {
            cout << computers[i].size() << ' ';
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Computers computers;
    vector<pair<int, int>> inputs;

    int numOfUser;
    cin >> numOfUser;

    int startTime, endTime;
    for (int i = 0; i < numOfUser; i++) {
        cin >> startTime >> endTime;
        inputs.push_back(make_pair(startTime, endTime));
    }

    sort(inputs.begin(), inputs.end());

    for (int i = 0; i < numOfUser; i++) {
        computers.Push(inputs[i]);
    }

    computers.Print();
}