#include <bits/stdc++.h>
#define DMAX 1030
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,a[DMAX],b[DMAX],lgmax[DMAX][DMAX],unde[DMAX][DMAX],i,j;
int main()
{
    fin>>n>>m;
    for(int i=1; i<=n; i++)
        fin>>a[i];
    for(int i=1; i<=m; i++)
        fin>>b[i];

    for(int i=n; i; i--)
        for(int j=m; j; j--)
            if(a[i]==b[j])
            {
                lgmax[i][j] = 1 + lgmax[i+1][j+1];
                unde[i][j] = 1;
            }
            else if(lgmax[i+1][j]>lgmax[i][j+1])
            {
                lgmax[i][j] = lgmax[i+1][j];
                unde[i][j] = 2;
            }
            else
            {
                lgmax[i][j] = lgmax[i][j+1];
                unde[i][j] = 3;
            }
    fout<<lgmax[1][1]<<'\n';
    i = 1;j=1;
    while(i<=n && j<=m)
    {
        if(unde[i][j]==1) {
            fout<<a[i]<<" ";
            i++;
            j++;
        }
        else if(unde[i][j] == 2)
            i++;
        else
            j++;
    }
    fout<<'\n';
    fout.close();
    return 0;
}
