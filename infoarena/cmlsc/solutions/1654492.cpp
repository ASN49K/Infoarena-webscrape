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
    for (i=1;i<=m;i++)//b
    {
        for (j=1;j<=n;j++)//a
        {
            if (a[j]==b[i])
            {
                mt[i][j]=mt[i-1][j-1]+1;
            }
            else mt[i][j]=max(mt[i-1][j],mt[i][j-1]);
        }
    }
}
int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    short i,j;
    f>>n>>m;
    for (i=1;i<=n;i++)
        f>>a[i];
    for (i=1;i<=m;i++)
        f>>b[i];
    pd();
    g<<mt[m][n]<<'\n';
    for (i=m,j=n;i>=1&&j>=1;)
    {
        if (b[i]==a[j])
        {
            sol.push_back(a[j]);
            i--,j--;
        }
        else
        {
            if (mt[i-1][j]>mt[i][j-1]) i--;
            else j--;
        }
    }
    for (i=sol.size()-1;i>=0;i--)
    {
        g<<sol[i]<<' ';
    }
    g<<'\n';
    f.close();
    g.close();
    return 0;
}
