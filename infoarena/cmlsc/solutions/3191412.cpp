#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025],b[1025],dp[1025][1025],m,n,lungime;
stack<int> sol;
int main()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>a[i];
    for(int i=1;i<=m;i++)
        fin>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    int i=n,j=m;
    while(i>0 && j>0)
        if(a[i]==b[j])
        {
            lungime++;
            sol.push(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    fout<<lungime<<'\n';
    while(!sol.empty())
    {
        fout<<sol.top()<<' ';
        sol.pop();
    }
    /*for(int i=1;i<=n;i++,fout<<'\n')
        for(int j=1;j<=m;j++)
            fout<<dp[i][j]<<' ';*/
    return 0;
}

/*
     l
5784592322223
321875423294
   c


*/