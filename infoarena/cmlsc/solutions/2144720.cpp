#include <bits/stdc++.h>

using namespace std;
int c1[1500],m,c2[1500],t[1100][1100],n,i,j,a,b,s[1100],poz;

void con(int x, int y)
{
    if (x>0 && y>0)
    if (c1[x]==c2[y]) {poz++; s[poz]=c2[y]; con(x-1,y-1);}
    else if (t[x][y-1]>t[x-1][y]) con(x,y-1); else con(x-1,y);

}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin>>n>>m;
    for (i=1;i<=n;i++)
        fin>>c1[i];
    for (i=1;i<=m;i++)
        fin>>c2[i];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        if (c1[i]==c2[j]) t[i][j]=t[i-1][j-1]+1;
        else t[i][j]=max(t[i-1][j],t[i][j-1]);
    }
    con(n,m);
    fout<<t[n][m]<<"\n";
    for (i=poz;i>=1;i--)
     fout<<s[i]<<" ";

    return 0;
}
