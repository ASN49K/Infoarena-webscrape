#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int v[100][100]={0},v1[100],v2[100],n,m;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

void findLCS(int x, int y)
{
    if (x==0 || y==0)
        return;
    else if (v1[x]==v2[y])
    {
        findLCS(x-1,y-1);
        g<<v1[x]<<" ";
    }
    else if (v[x-1][y]>v[x][y-1])
    {
        findLCS(x-1,y);
    }
    else findLCS(x,y-1);
}

int main()
{
    int i,j,maxim=0;
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>v1[i];
    for (i=1;i<=m;i++)
        f>>v2[i];
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
                if (v1[i]==v2[j])
                    v[i][j]=1+v[i-1][j-1];
                else
                {
                    v[i][j]=max(v[i-1][j],v[i][j-1]);
                }
                if (v[i][j]>maxim)
                    maxim=v[i][j];
        }
    }
    g<<maxim<<endl;
    findLCS(n,m);
    return 0;
}
