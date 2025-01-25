// 2460.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int numOfPeopleInTrain = 0;
    int maxNum = 0;
    for (int i = 0; i < 10; ++i) {
        int out, in;
        cin >> out >> in;
        numOfPeopleInTrain -= out;
        numOfPeopleInTrain += in;
        maxNum = max(maxNum, numOfPeopleInTrain);
    }

    cout << maxNum;
}