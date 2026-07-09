#include <iostream>
#include <fstream>
#define NM 1024
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,a[NM][NM],x[NM],y[NM];

void cit()
{
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>x[i];
    for(int i=1;i<=n;i++)
        fin>>y[i];
}

void sclm()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else if(a[i][j-1]>a[i-1][j])
                a[i][j]=a[i][j-1];
            else a[i][j]=a[i-1][j];
        }
}

void dr(int i,int j)
{
    if(i!=0&&j!=0)
        if(x[i]==y[j])
        {
            dr(i-1,j-1);
            fout<<x[i]<<' ';
        }
        else if(a[i][j]==a[i][j-1])
            dr(i,j-1);
        else dr(i-1,j);

}

int main()
{
    cit();
    sclm();
    fout<<a[n][m]<<'\n';
    dr(n,m);
    return 0;
}
