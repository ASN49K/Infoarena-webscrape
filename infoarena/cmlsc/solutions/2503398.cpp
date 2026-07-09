#include<bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025][1025],b[1025],c[1025],sub[1025];
int n,m,i,j,x=0;
int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    fin>>b[i];
    for(j=1;j<=m;j++)
    fin>>c[j];

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(b[i]==c[j])
            a[i][j]=a[i-1][j-1]+1;
        else
            a[i][j]=max(a[i-1][j] , a[i][j-1]);
        }
    }
    i=n;
    j=m;
    while(a[i][j])
    {
        while(a[i][j]==a[i-1][j])
        i--;
        while(a[i][j]==a[i][j-1])
        j--;
        x++;
        sub[x]=b[i];
        i--;
        j--;
    }
    fout<<a[n][m]<<" ";
    fout<<endl;
    for(i=x;i>=1;i--)
    fout<<sub[i]<<" ";
    return 0;
}
