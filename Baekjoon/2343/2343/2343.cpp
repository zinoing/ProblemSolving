#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> courses;
    int numOfCourses;
    int N;
    cin >> numOfCourses >> N;

    int course = 0;
    int sum = 0;
    int max = 0;

    for (int i = 0; i < numOfCourses; i++) {
        cin >> course;
        if (course > max)
            max = course;
        sum += course;
        courses.push_back(course);
    }



    int l, r, mid;
    l = max;
    r = sum;

    while (l <= r) {
        mid = (l + r) / 2;

        int minSizeOfBlueray = 0;
        sum = 0;

        for (int i = 0; i < numOfCourses; i++) {
            int course = courses[i];
            // 수업을 더하여 블루레이 값이 mid 보다 커진다면
            if (sum + course > mid) {
                ++minSizeOfBlueray;
                sum = 0;
            }
            sum += course;
        }

        if (sum != 0) {
            ++minSizeOfBlueray;
        }

        // N 보다 큰 값이 나올 경우 우측으로 이동
        if (minSizeOfBlueray > N) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << l;

    return 0;
}
