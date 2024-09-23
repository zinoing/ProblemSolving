// 동영상 재생기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getMin(string time) {
    int min = (int)(time[0] - '0') * 10 + (int)(time[1] - '0');
    return min;
}

int getSec(string time) {
    int sec = (int)(time[3] - '0') * 10 + (int)(time[4] - '0');
    return sec;
}

string setTime(string currentTime, int sec, string video_len) {
    int currentMin = getMin(currentTime);
    int currentSec = getSec(currentTime);

    currentSec += sec;

    if (currentSec >= 60) {
        currentMin += 1;
        currentSec -= 60;
    }

    if (currentSec < 0) {
        if (currentMin == 0) {
            currentMin = 0;
            currentSec = 0;
        }
        else {
            currentMin -= 1;
            currentSec += 60;
        }
    }

    if (currentMin > getMin(video_len)) {
        currentMin = getMin(video_len);
        currentSec = getSec(video_len);
    }

    if ((currentMin == getMin(video_len)) && currentSec > getSec(video_len)) {
        currentSec = getSec(video_len);
    }

    string time(5, ' ');
    time[2] = ':';

    time[1] = '0' + currentMin % 10;
    currentMin /= 10;
    time[0] = '0' + currentMin;

    time[4] = '0' + currentSec % 10;
    currentSec /= 10;
    time[3] = '0' + currentSec;

    cout << time << endl;
    return time;
}

bool inOpeningTime(string currentTime, string op_start, string op_end) {
    int op_start_min = getMin(op_start);
    int op_start_sec = getSec(op_start);

    int op_end_min = getMin(op_end);
    int op_end_sec = getSec(op_end);

    int min = getMin(currentTime);
    int sec = getSec(currentTime);

    if (min < op_start_min) return false;
    if (min == op_start_min && sec < op_start_sec) return false;
    if (min > op_end_min) return false;
    if (min == op_end_min && sec > op_end_sec) return false;

    return true;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

    for (string command : commands) {
        if (inOpeningTime(pos, op_start, op_end)) {
            pos = op_end;
        }

        if (command == "prev") {
            pos = setTime(pos, -10, video_len);
        }

        if (command == "next") {
            pos = setTime(pos, 10, video_len);
        }
    }

    if (inOpeningTime(pos, op_start, op_end)) {
        pos = op_end;
    }

    string answer = pos;
    return answer;
}