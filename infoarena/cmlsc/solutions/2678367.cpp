#include <fstream>
#include <algorithm>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
const int N = 1030;
int n,m,a[N],b[N],sol[N][N];
void afisare(int i,int j)
{
    if(sol[i][j]==0)
        return;
    if(a[i]==b[j])
    {
        afisare(i-1,j-1);
        g<<a[i]<<' ';
    }
    else if(sol[i-1][j]>=sol[i][j-1])
        afisare(i-1,j);
    else
        afisare(i,j-1);
}
int main()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)f>>a[i];
    for(int i=1;i<=m;i++)f>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i]==b[j])
                sol[i][j]=sol[i-1][j-1]+1;
            else
                sol[i][j]=max(sol[i-1][j],sol[i][j-1]);
    g<<sol[n][m]<<'\n';
    afisare(n,m);
    return 0;
}
