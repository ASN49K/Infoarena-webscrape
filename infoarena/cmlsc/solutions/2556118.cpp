
#include <iostream>
#include <fstream>

using namespace std;
ifstream r("cmlsc.in");
ofstream w("cmlsc.out");
int dinamica[1028][1028], v[1028], g[1028], fin[1028];
int main()
{
    int m, n, x, lungime=0, cnt;
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
        dinamica[0][0] = 1;
    for(int i=1; i<m; i++)
    {
        if(v[i]==g[0])
        {
            dinamica[i][0]=dinamica[i-1][0] + 1;
        }
        else{
            dinamica[i][0]=dinamica[i-1][0];
        }
    }
    for(int i=1; i<n; i++)
    {
        if(g[i]==v[0])
        {
            dinamica[0][i]= dinamica[0][i] + 1;
        }
        else{
            dinamica[0][i]=dinamica[0][i-1];
        }
    }
    for(int i=1; i<m; i++)
    {
        for(int j=1; j<n; j++)
        {
            if(v[i]==g[j])
            {
                dinamica[i][j]=dinamica[i-1][j-1]+1;
            }
            else
            {
                dinamica[i][j]=max(dinamica[i-1][j],dinamica[i][j-1]);
            }
        }
    }
    int maxim=dinamica[m-1][n-1], ans=0;
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
            if(dinamica[m-1][n]>=dinamica[m][n-1])
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
    w<<"\n";
    return 0;
}
