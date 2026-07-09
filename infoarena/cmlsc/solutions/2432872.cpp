#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1027][1027];

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

    if (lengthOfSecond > lengthOfFirst)
    {
        swap(second, first);
        swap(lengthOfFirst, lengthOfSecond);
    }

    for (int i = 1; i <= lengthOfFirst; i++) {
        for (int j = 1; j <= lengthOfSecond; j++) {
            if (first[i] == second[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << dp[lengthOfFirst][lengthOfSecond] << "\n";

    int step = 0;
    for (int i = 1; i <= lengthOfFirst; i++) {
        for (int j = 1; j <= lengthOfSecond; j++) {
            if (dp[i][j] > step) {
                cout << first[i] << " ";
                step = dp[i][j];
            }
        }
    }
}
