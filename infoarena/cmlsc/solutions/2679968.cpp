#include <bits/stdc++.h>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int a[1027][1027];
int x[1027];
int y[1027];
int sir[1027];
int main()
{
    int n, m;
    in>>n>>m;
    for(int i=1;i<=n;i++)
    {
        in>>x[i];
    }
    for(int j=1;j<=m;j++)
    {
        in>>y[j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(x[i]==y[j])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=max(a[i-1][j], a[i][j-1]);
            }
        }
    }

    out<<a[n][m];
    int i=n, j= m, bst =0;
    while(i)
    {
        if(x[i] == y[j])
        {
            sir[++bst] = x[i]; i--; j--;
        }
        else
        {
            if(a[i-1][j] < a[i][j-1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    out<<'\n';
    for(int i=bst; i>0;i--)
    {
        out<<sir[i]<<" ";
    }
}

