#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
vector<int>v;
int n,m,a[1025][1025],b[1025],c[1025];
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>b[i];
    for(int i=1;i<=m;i++)
        f>>c[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(b[i]==c[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    g<<a[n][m]<<'\n';
    int x=n,y=m;
    while(v.size()!=a[n][m])
    {
        if(b[x]==c[y])
        {
            v.push_back(b[x]);
            x--;
            y--;
        }
        else
        if(a[x-1][y]>=a[x][y-1])
            x--;
        else
            y--;
    }
    while(v.size())
    {
        g<<v.back()<<" ";
        v.pop_back();
    }
    return 0;
}
