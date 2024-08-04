#define INT_MAX 2147483647
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int numOfHolesInMultitab, numOfUses;
int minCnt = INT_MAX;
map<int, queue<int>> nextUse;

int findTheFarthestTab(vector<int>& multitab, int currentIdx) {
    int maxDistance = -1;
    int maxIdx = -1;

    for (int i = 0; i < numOfHolesInMultitab; i++) {
        int appliance = multitab[i];
        if (nextUse[appliance].empty()) {
            return i;
        }

        while (!nextUse[appliance].empty() && nextUse[appliance].front() <= currentIdx) {
            nextUse[appliance].pop();
        }

        if (nextUse[appliance].empty()) {
            return i;
        }
        else {
            int distance = nextUse[appliance].front();
            if (distance > maxDistance) {
                maxDistance = distance;
                maxIdx = i;
            }
        }
    }
    return maxIdx;
}

void dfs(vector<int>& multitab, vector<int>& electricalApplianceSequence, int idx, int cnt) {
    if (idx == numOfUses) {
        if (cnt < minCnt)
            minCnt = cnt;
        return;
    }

    int currentAppliance = electricalApplianceSequence[idx];

    for (int i = 0; i < numOfHolesInMultitab; i++) {
        if (multitab[i] == 0) {
            multitab[i] = currentAppliance;
            dfs(multitab, electricalApplianceSequence, idx + 1, cnt);
            return;
        }

        if (multitab[i] == currentAppliance) {
            dfs(multitab, electricalApplianceSequence, idx + 1, cnt);
            return;
        }
    }

    int tabToPullOut = findTheFarthestTab(multitab, idx);
    int originalValue = multitab[tabToPullOut];
    multitab[tabToPullOut] = currentAppliance;
    dfs(multitab, electricalApplianceSequence, idx + 1, cnt + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numOfHolesInMultitab >> numOfUses;
    vector<int> multitab(numOfHolesInMultitab, 0);
    vector<int> electricalApplianceSequence(numOfUses);

    for (int i = 0; i < numOfUses; i++) {
        int electricalAppliance;
        cin >> electricalAppliance;
        electricalApplianceSequence[i] = electricalAppliance;
        nextUse[electricalAppliance].push(i);
    }

    dfs(multitab, electricalApplianceSequence, 0, 0);

    cout << minCnt;

    return 0;
}
