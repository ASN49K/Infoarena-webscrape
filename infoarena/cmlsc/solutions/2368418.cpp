#include <bits/stdc++.h>
#define N 1025
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[N],b[N],n,m,c[N][N];
vector<int>sol;

void afis()
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            fout<<c[i][j]<<" ";
        fout<<endl;
    }
}
int main()
{
    int i,j,k;

    fin>>n>>m;

    for(i=1;i<=n;i++)
        fin>>a[i];
    for(i=1;i<=m;i++)
        fin>>b[i];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);

    fout<<c[n][m]<<"\n";

    i=n;
    j=m;
    k=c[n][m];

    while(k!=0)
    {
        if(c[i][j]==c[i-1][j])
            i--;
        else
            if(c[i][j]==c[i][j-1])
                j--;
            else
            {
                sol.push_back(a[i]);
                i--;
                j--;
                k--;
            }
    }

    for(i=sol.size()-1;i>=0;i--)
        fout<<sol[i]<<" ";
    return 0;
}
