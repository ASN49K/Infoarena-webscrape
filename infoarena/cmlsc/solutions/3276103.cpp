#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int A[1025],B[1025],dp[1025][1025];
vector<int> v;
int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>A[i];
    for(int i=1; i<=m; i++)
        fin>>B[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(A[i]==B[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int i=n,j=m;
    while(dp[i][j])
    {
        if(A[i]==B[j])
        {
            v.push_back(B[j]);
            i--;
            j--;
        }
        else if(dp[i][j-1]>dp[i-1][j])
            j--;
        else i--;
    }
    reverse(v.begin(),v.end());
    fout<<v.size()<<'\n';
    for(int i=0;i<v.size();i++)
        fout<<v[i]<<' ';
    return 0;
}
