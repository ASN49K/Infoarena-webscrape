#include <bits/stdc++.h>

using namespace std;
ifstream r("cmlsc.in");
ofstream w("cmlsc.out");
int d[1028][1028], v[1028], g[1028], fin[1028];
int main()
{
    int m, n;
    r>>m>>n;
    for(int i=0; i<m; i++)
    {
        r>>v[i];
    }
    for(int i=0; i<n; i++)
    {
        r>>g[i];
    }
    if (v[0] == g[0])
    {
        d[0][0] = 1;
    }
    for(int i=1; i<m; i++)
    {
        if(v[i]==g[0])
        {
            d[i][0]=1;
        }
        else
        {
            d[i][0]=d[i-1][0];
        }
    }
    for(int i=1; i<n; i++)
    {
        if(g[i]==v[0])
        {
            d[0][i]=1;
        }
        else
        {
            d[0][i]=d[0][i-1];
        }
    }
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(v[i]==g[j])
            {
                d[i][j]=d[i-1][j-1]+1;
            }
            else
            {
                d[i][j]=max(d[i-1][j],d[i][j-1]);
            }
        }
    }
    int maxim=d[m-1][n-1], ans=0;
    w<<maxim<<"\n";
    m --;
    n --;
    while(maxim!=0)
    {
        if(v[m]==g[n])
        {
            fin[ans]=v[m];
            ans++;
            n--;
            m--;
            maxim--;
        }
        else
        {
            if(m>=1 && d[m-1][n]>=d[m][n-1])
            {
                m--;
            }
            else
            {
                n--;
            }
        }
    }
    for(int i=ans-1; i>=0; i--)
    {
        w<<fin[i]<<" ";
    }
    return 0;
}
