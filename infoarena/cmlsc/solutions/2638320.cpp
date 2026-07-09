#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
int **d;
int main()
{
    vector<int> a, b;
    int m, n, i, j;
    ifstream f("cmlsc.in");
    f>>m>>n;
    d=(int**)malloc((m+1)*sizeof(int*));
    for(int i=0;i<=m;i++)
    {
        d[i]=(int*)malloc((n+1)*sizeof(int));
        d[i][0]=0;
    }
    for(int i=1;i<=n;i++)
        d[0][i]=0;
    a.resize(m);
    b.resize(n);
    for(int i=0;i<m;i++)
        f>>a[i];
    for(int i=0;i<n;i++)
        f>>b[i];
    f.close();
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(a[i-1]==b[j-1])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
    i=m;
    j=n;
    stack<int> res;
    while(i&&j)
        if(a[i-1]==b[j-1])
        {
            res.push(a[i-1]);
            i--;
            j--;
        }
        else if(d[i][j-1]>d[i-1][j])
            j--;
        else
            i--;
    ofstream g("cmlsc.out");
    g<<d[m][n]<<'\n';
    while(res.size())
    {
        g<<res.top()<<' ';
        res.pop();
    }
    g.close();
    return 0;
}
