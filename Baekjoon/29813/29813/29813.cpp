#include <iostream>
#include <deque>
using namespace std;

class CircularQueue {
    deque<pair<string, int>> circularQueue;
    int count;

public:
    CircularQueue() {};

    int Size() {
        return circularQueue.size();
    }

    void Enqueue(pair<string, int> value) {
        circularQueue.push_back(value);
    }

    void Rotate() {
        circularQueue.push_back(Dequeue());
    }

    pair<string, int> Dequeue() {
        pair<string, int> dequedValue = circularQueue.front();
        circularQueue.pop_front();
        return dequedValue;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    CircularQueue line;

    int numOfStudents;
    cin >> numOfStudents;

    string initial;
    int id;
    for (int i = 0; i < numOfStudents; i++) {
        cin >> initial >> id;
        line.Enqueue(make_pair(initial, id));
    }

    while (line.Size() > 1) {
        pair<string, int> student = line.Dequeue();
        for (int i = 0; i < student.second-1; i++) {
            line.Rotate();
        }
        line.Dequeue();
    }

    cout << line.Dequeue().first;
}

