#include <bits/stdc++.h>
using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout  ("cmlsc.out");

const int DIM = 1050;

int a[DIM], b[DIM], dp[DIM][DIM];
int n, m;

int main (){
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

    int i = n, j = m, len;
    stack <int> sol;
    len = dp[i][j];
    fout<<len<<"\n";
    while(len != 0)
        if(a[i] == b[j])
            sol.push(a[i]), len--, i--, j--;
        else
            if(dp[i-1][j] > dp[i][j-1])
                i--;
            else
                j--;

    while(!sol.empty())
        fout<<sol.top()<<" ", sol.pop();
    return 0;
}
