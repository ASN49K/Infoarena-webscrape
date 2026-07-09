#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

int dp[1024][1024];

int main() {
    short lengthOfFirst, lengthOfSecond;
    cin >> lengthOfFirst >> lengthOfSecond;

    vector<int> first;
    for (int i = 1; i <= lengthOfFirst; i++) {
        int a;
        cin >> a;
        first.push_back(a);
    }

    vector<int> second;
    for (int i = 1; i <= lengthOfSecond; i++) {
        int a;
        cin >> a;
        second.push_back(a);
    }

    vector<int> commSubs;
    memset(dp, 0, sizeof dp);
    for (int i = 0; i < lengthOfFirst; i++) {
        for (int j = 0; j < lengthOfSecond; j++) {
            if (first[i] == second[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
                commSubs.push_back(first[i]);
                break;
            }
            else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[lengthOfFirst][lengthOfSecond] << '\n';

    for (int i = 0; i < commSubs.size(); i++)
    {
        cout << commSubs[i] << " ";
    }
}
