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
#define nr(i,j) ((i-1)*m+j)
#define take_x(k) ((k-1)/m+1)
#define take_y(k) ((k-1)%m+1)

int a[nmax],b[nmax],dp[nmax][nmax],p[nmax*nmax];
int i,j,n,m,nr;

void afis(int z)
    {
    int x=take_x(z),y=take_y(z);
    if(p[z]) afis(p[z]);
    if(a[x]==b[y]) cout<<a[x]<<' ';
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
            if(a[i]==b[j])
                {
                dp[i][j]=1+dp[i-1][j-1];
                if(i-1>0 && j-1>0) p[nr(i,j)]=nr(i-1,j-1);
                }
            if(dp[i][j]<dp[i-1][j])
                {
                dp[i][j]=dp[i-1][j];
                 if(i-1>0 && j>0) p[nr(i,j)]=nr(i-1,j);
                }
            if(dp[i][j]<dp[i][j-1])
                {
                dp[i][j]=dp[i][j-1];
                if(i>0 && j-1>0)  p[nr(i,j)]=nr(i,j-1);
                }
            }

    cout<<dp[n][m]<<'\n';
    afis(nr(n,m));
    cerr<<'\n'<<nr;
    return 0;
    }
