#include <vector>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1024][1024];

int main() {
    short lengthOfFirst, lengthOfSecond;
    cin >> lengthOfFirst >> lengthOfSecond;

    vector<int> first;
    first.push_back(0);
    for (int i = 1; i <= lengthOfFirst; i++) {
        int a;
        cin >> a;
        first.push_back(a);
    }

    vector<int> second;
    second.push_back(0);
    for (int i = 1; i <= lengthOfSecond; i++) {
        int a;
        cin >> a;
        second.push_back(a);
    }

    vector<int> commSubs;
    for (int i = 1; i <= lengthOfFirst; i++) {
        for (int j = 1; j <= lengthOfSecond; j++) {
            if (first[i] == second[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                commSubs.push_back(first[i]);
            } else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[lengthOfFirst][lengthOfSecond] << "\n";

    for (int i = 0; i < commSubs.size(); i++) {
        cout << commSubs[i] << " ";
    }
}
