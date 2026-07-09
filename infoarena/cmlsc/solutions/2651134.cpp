#include <bits/stdc++.h>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define Nmax 1025
int a[Nmax],b[Nmax];
int DP[Nmax][Nmax];
stack < int > bst;


int main()
{
    int n,m;
    f>>n>>m;
    int i;
    for(i=1; i<=n; i++)
        f>>a[i];
    for(i=1; i<=m; i++)
        f>>b[i];
    int j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i] == b[j])
                DP[i][j] = 1 + DP[i-1][j-1];
            else
                DP[i][j] = max (DP[i-1][j], DP[i][j-1]);
    g<<DP[n][m]<<'\n';
    i=n;
    j=m;
    while(i and j)
    {

        if(a[i] == b[j])
        {
            bst.push(a[i]);
            --i;
            --j;
        }
        else if(DP[i-1][j] > DP[i][j-1])
            --i;
        else --j;
    }
    //cout<<i<<' '<<j;
    //  g<<"DA";
   while(!bst.empty())
   {
       g<<bst.top()<<' ';
       bst.pop();
   }
    return 0;
}
