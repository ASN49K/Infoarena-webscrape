#include <iostream>
#include <fstream>
#include<stack>
using namespace std;
ifstream si("cmlsc.in");
ofstream so("cmlsc.out");
int v[1025][1025];
int x[1025];
int y[1025];
stack<int> sol;
int main()
{
    int n,m;
    si>>n>>m;
    int i,j;
    for(i=1;i<=n;++i)
        si>>x[i];
    for(j=1;j<=m;++j)
    {
        si>>y[j];
    }
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(x[i]==y[j])
            {
                v[i][j]=v[i-1][j-1]+1;
            }
            else
            {
                v[i][j]=max(v[i-1][j],v[i][j-1]);
            }
        }
    }
    so<<v[n][m]<<'\n';
    i=n;
    j=m;
    while(i&&j)
    {
        if(x[i]==y[j])
        {
            sol.push(x[i]);
            i--;
            j--;
        }
        else
        {
            if(v[i][j-1]>v[i-1][j])
            {
                --j;
            }
            else
                --i;
        }
    }
    while(!sol.empty())
    {
        so<<sol.top()<<' ';
        sol.pop();
    }
    return 0;
}
