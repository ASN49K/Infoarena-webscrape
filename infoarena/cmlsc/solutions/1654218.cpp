#include <fstream>
#include <algorithm>
#include <vector>
#define w 257
#define ws 1025
using namespace std;
short mt[w][w];
vector <short>sol;
short a[ws],b[ws];
short n,m;
void pd()
{
    int i,j;
    for (i=1;i<=m-1;i++)//b
    {
        for (j=1;j<=n-1;j++)//a
        {
            if (a[j]==b[i])
            {
                mt[i][j]++;
                sol.push_back(b[i]);
            }
            mt[i+1][j]=max(mt[i+1][j],mt[i][j]);
            mt[i][j+1]=max(mt[i][j+1],mt[i][j]);
        }
        if (a[n]==b[i])
        {
            mt[n][j]++;
            sol.push_back(b[i]);
        }
        mt[i+1][j]=max(mt[i+1][j],mt[i][j]);
    }
    for (j=1;j<=n-1;j++)//a
    {
        if (a[j]==b[m])
        {
            mt[m][j]++;
            sol.push_back(b[m]);
        }
        mt[m][j+1]=max(mt[m][j+1],mt[m][j]);
    }
    if (a[n]==b[m])
    {
        mt[m][n]++;
        sol.push_back(b[m]);
    }
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    short i;
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (i=1;i<=m;i++)
        f>>b[i];
    pd();
    g<<sol.size()<<'\n';
    for (i=0;i<sol.size();i++)
    {
        g<<sol[i]<<' ';
    }
    g<<'\n';
    f.close();
    g.close();
    return 0;
}
