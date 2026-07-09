#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[2025][2025],n,m,v1[2025],v2[2025];
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>v1[i];
    for(int i=1; i<=m; i++)
        f>>v2[i];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(v1[i]==v2[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    g<<a[n][m]<<'\n';
    stack<int> S;
    for(int i=n; i>0;)
        for(int j=m; j>0;)
        {
            if(v1[i]==v2[j])
                S.push(v1[i]),i--,j--;
            else
            {
                if(a[i][j-1]>a[i-1][j])
                    j--;
                else
                    i--;
            }
        }
    while(!S.empty())
        g<<S.top()<<' ',S.pop();

    return 0;
}
