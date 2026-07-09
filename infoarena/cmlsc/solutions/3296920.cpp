#include <fstream>
#include <vector>
#include <stack>
#define MAX_SIZE 1024
using namespace std;

vector<short> a, b;
short dp[MAX_SIZE + 2][MAX_SIZE + 2];

void readArrays(string filename) {
    int n, m;
    short x;
    ifstream fin(filename);
    fin >> n >> m;

    for (int i = 0; i < n; ++i) {
        fin >> x;
        a.push_back(x);
    }

    for (int i = 0; i < m; ++i) {
        fin >> x;
        b.push_back(x);
    }

    fin.close();
}

int longestCommonSubsequence() {
    for (int i = 1; i <= a.size(); ++i) {
        for (int j = 1; j <= b.size(); ++j) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else 
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[a.size()][b.size()];
}

void printSolution(string filename) {
    ofstream fout(filename);

    fout << longestCommonSubsequence() << "\n";
    stack<short> sol;

    int i, j;

    i = a.size();
    j = b.size();

    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            sol.push(a[i - 1]);
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else 
            j--;
    }

    while (!sol.empty()) {
        fout << sol.top() << " ";
        sol.pop();
    }

    fout << "\n";

    fout.close();
}

int main() {
    readArrays("cmlsc.in");
    printSolution("cmlsc.out");
    return 0;

}