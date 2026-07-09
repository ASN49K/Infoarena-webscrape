#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#ifdef INFOARENA
ifstream f("cmlsc.in");
#define cout g
#else
ifstream f("date.in");
#endif // INFOARENA

ofstream g("cmlsc.out");

#define nmax 1026

int a[nmax],b[nmax],dp[nmax][nmax];
int i,j,n,m;

void afis(int x,int y)
    {
        if(x==0 || y==0) return;
        if(a[x]==b[y])
        {
            afis(x-1,y-1);
            cout<<a[x]<<' ';
            return;
        }
        if(dp[x-1][y]>dp[x][y-1]) afis(x-1,y);
        else afis(x,y-1);
    }

int main()
    {
    f>>n>>m;
    for(i=1; i<=n; ++i) f>>a[i];
    for(i=1; i<=m; ++i) f>>b[i];
    int x;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            {
            if(a[i]==b[j])   dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

    cout<<dp[n][m]<<'\n';
    afis(n,m);
    return 0;
    }
