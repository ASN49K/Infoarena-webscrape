#include <iostream>
#include <fstream>
#define MAXN 1024
using namespace std;

ifstream f1("cmlsc.in");
ofstream f2("cmlsc.out");
int n,m,a[MAXN],b[MAXN],c[MAXN][MAXN];

void afisare(int i, int j)
{
    if(c[i][j]!=0)
    {
        if(a[i]==b[j])
        {
            afisare(i-1,j-1);
            f2<<a[i];
        }
        else
            if(c[i][j-1]>c[i-1][j])
                afisare(i,j-1);
            else
                afisare(i-1,j);
    }
}

int main()
{
    f1>>n>>m;
    for(int i=1;i<=n;i++)
        f1>>a[i];
    for(int i=1;i<=m;i++)
        f1>>b[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                if(c[i-1][j]>c[i][j-1])
                    c[i][j]=c[i-1][j];
                else
                    c[i][j]=c[i][j-1];
        }
    f2<<c[n][m]<<endl;
    afisare(n,m);
    return 0;
}
