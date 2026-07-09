#include <fstream>
#include <vector>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

auto computeDP(unsigned int n, unsigned int m){
    vector<vector<int> > dp(n+1, vector<int>(m+1, 0));
    vector<int> a(n+1);
    vector<int> b(m+1);

    for(int i=1;i<=n;i++)
        fin >> a[i];
    for(int i=1;i<=m;i++)
        fin >> b[i];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j] = ((a[i]==b[j]) ? dp[i-1][j-1]+1 : ( (dp[i-1][j]>dp[i][j-1])?dp[i-1][j]:dp[i][j-1] ));

    return dp;
}

void backtrack(unsigned int i, unsigned int j, vector<vector<int> > &mat, unsigned int n, unsigned int m){
    if(i==0 || j==0){
        fout<<mat[n][m]<<"\n";
        return;
    }
    if(mat[i-1][j]==mat[i][j])
        backtrack(i-1, j, mat, n, m);
    else if(mat[i][j-1]==mat[i][j])
        backtrack(i,j-1,mat, n, m);
    else{
        backtrack(i-1, j-1, mat, n, m);
        fout<<mat[i][j]<<" ";
    }
}

int main() {
    unsigned int n, m;
    fin >> n >> m;

    auto mat = computeDP(n,m);
    backtrack(n, m, mat, n, m);

    return 0;
}