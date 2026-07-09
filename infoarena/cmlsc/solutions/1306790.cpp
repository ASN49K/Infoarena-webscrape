#include<stdio.h>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
    ifstream si;
    si.open("cmlsc.in");
    ofstream so;
    so.open("cmlsc.out");
    int n,m;
    si>>n>>m;
    int v[n],x[m];
    int i;
    for(i=0;i<n;++i)
        si>>v[i];
    for(i=0;i<m;++i)
        si>>x[i];
    int sol[n+1][m+1];
    int j;
    for(i=0;i<=m;++i)
        sol[0][i]=0;
    for(i=0;i<=n;++i)
        sol[i][0]=0;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
        {
            if(v[i-1]==x[j-1])
            {
                sol[i][j]=sol[i-1][j-1]+1;
            }
            else
            {
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
            }
        }
    so<<sol[n][m]<<'\n';
    stack<int> s;
    i=n;
    j=m;
    while(i&&j)
    {
        if(v[i-1]==x[j-1])
        {
            s.push(v[i-1]);
            --i;
            --j;
        }
        else
            if(sol[i-1][j]>sol[i][j-1])
                --i;
            else
                --j;
    }
    while(s.size()>0)
    {
        so<<s.top()<<' ';
        s.pop();
    }
    so<<'\n';
}
