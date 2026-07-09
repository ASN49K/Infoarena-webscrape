#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,x[1025],y[1025],lcs[1025][1025];
void rezolvare()
{
    int k,h;
    for(k=1;k<=n;k++)
        for(h=1;h<=m;h++)
        if(x[k]==y[h])
           lcs[k][h]=lcs[k-1][h-1]+1;
        else
            lcs[k][h]=max(lcs[k][h-1],lcs[k-1][h]);
}
void afisare_sol_max(int k,int h)
{
    if(lcs[k][h])
        if(x[k]==y[h])
        {
              afisare_sol_max(k-1,h-1);
              g<<x[k]<<" ";
        }
    else
    {
        if(lcs[k][h]==lcs[k-1][h])
            afisare_sol_max(k-1,h);
        else
            if(lcs[k][h]==lcs[k][h-1])
            afisare_sol_max(k,h-1);
    }
}
int main()
{
    int i;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];
    rezolvare();
    g<<lcs[n][m]<<"\n";
    afisare_sol_max(n,m);
    return 0;
}
