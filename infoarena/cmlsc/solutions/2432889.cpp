#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1025][1025];

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

    for (int i = 1; i <= lengthOfFirst; i++) {
        for (int j = 1; j <= lengthOfSecond; j++) {
            if (first[i] == second[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[lengthOfFirst][lengthOfSecond] << "\n";

    vector<int> commSubs;
    int i = lengthOfFirst, j = lengthOfSecond;
    while (i > 0 && j > 0) {
        if (first[i] == second[j]) {
            commSubs.push_back(first[i]);
            i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else j--;
    }

    for (int i = commSubs.size() - 1; i >= 0; i--) {
        cout << commSubs[i] << " ";
    }
}
