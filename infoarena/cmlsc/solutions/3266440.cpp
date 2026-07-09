#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {

    int n,m;

    fin >> n >> m;

    vector<int> A(n+1), B(m+1);

    for(int i=0; i<n; i++)
        fin >> A[i];
    
    for(int i=0; i<m; i++)
        fin >> B[i];
    
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(A[i-1] == B[j-1])
                dp[i][j] = 1+dp[i-1][j-1];
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    fout << dp[n][m] << endl;

    vector<int> sol;

    int line = n, column = m;

    while(line >=1 && column >=1) {
        if(A[line-1] == B[column-1]) {
            sol.push_back(A[line-1]);
            line--;
            column--;
        }
        else {
            if(dp[line-1][column] >= dp[line][column-1])
                line--;
            else
                column--;
        }
    }

    
    reverse(sol.begin(), sol.end());

    for(auto e : sol)
        fout << e << ' ';


    return 0;
}