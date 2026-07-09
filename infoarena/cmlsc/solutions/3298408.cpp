#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n,m;
    int a[1025], b[1025];

    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    f>>n>>m;
    for (int i = 1; i <= n; i++) {
        f>> a[i];
    }

    for (int i = 1; i<=m; i++) {
        f>>b[i];
    }

    int longestSubarray[1025][1025];
    int maxLength = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<=m; j++) {
            if (a[i] == b[j])
            {
                longestSubarray[i][j] = 1 + longestSubarray[i-1][j-1];
                if (longestSubarray[i][j] > maxLength) {
                    maxLength = longestSubarray[i][j];
                }
            }
            else {
                longestSubarray[i][j] = max(longestSubarray[i-1][j], longestSubarray[i][j-1]);
            }
        }
    }

        int line = n;
        int column = m;
        int solution[1025];
        for (int i = 1; i <=maxLength; i++) {
            while (longestSubarray[line][column] == longestSubarray[line-1][column]) {
                line--;
            }
            while (longestSubarray[line][column-1] == longestSubarray[line][column]) {
                column--;
            }

            solution[i] = a[line];
            line--;
        } 

    g<< maxLength << "\n";

    for (int i = maxLength; i > 0; i--) {
        g<< solution[i]<< " ";
    }
    return 0;
}