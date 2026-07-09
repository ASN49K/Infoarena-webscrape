#include <bits/stdc++.h>

using namespace std;
int **d;
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n, m, i, j;
    f>>m>>n;
    vector<int> a, b;
    stack<int> s;
    a.resize(m+1);
    b.resize(n+1);

    d=(int**)malloc((m+1)*sizeof(int*));
    for(int i=0; i<=m; i++)
        d[i]=(int*)malloc((n+1)*sizeof(int));

    for(int i=0; i<=m; i++)
        d[i][0]=0;
    for(int i=0; i<=n;i++)
        d[0][i]=0;

    for(int i=1; i<=m; i++)
        f>>a[i];
    for(int j=1; j<=n; j++)
        f>>b[j];
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1], d[i-1][j]);

    g<<d[m][n]<<'\n';
    i=m;
    j=n;
    while(i&&j)
        if(a[i]==b[j])
        {
            s.push(a[i]);
            i--;
            j--;
        }
        else
            if(d[i][j-1]>d[i-1][j])
                j--;
            else
                i--;
    while(s.size())
    {
        g<<s.top()<<" ";
        s.pop();
    }
    for(int i=0; i<=m; i++)
        free(d[i]);
    free(d);
    f.close();
    g.close();
    return 0;
}
