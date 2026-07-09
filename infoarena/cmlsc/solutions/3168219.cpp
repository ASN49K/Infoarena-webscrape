#include<bits/stdc++.h>
#define DIM 2001
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[DIM], b[DIM], ans[DIM];
int dp[DIM][DIM];
int n, m, i, j, ind;
int main(){
    fin >> n >> m;
    for(i=0;i<n;i++)
        fin >> a[i];
    for(i=0;i<m;i++)
        fin >> b[i];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    for(i=n;i>=1; i = i)
        for(j=m;j>=1 && i>=1;i = i){
            if(a[i - 1] == b[j - 1]) ans[++ind] = a[i - 1], i--, j--;
            else if(dp[i - 1][j] < dp[i][j - 1]) j--;
            else i--;
        }
    fout << ind << "\n";
    for(i=ind;i>=1;i--)
        fout << ans[i] << " ";
}
