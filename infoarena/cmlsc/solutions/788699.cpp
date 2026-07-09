#include <iostream>
#include <fstream>
#define Maxim(a,b) a>b?a:b
using namespace std;
fstream f("cmlsc.in", ios::in),
        g("cmlsc.out", ios::out);
int c[1024][1024], a[1024], b[1024];

void PrintSol(int i, int j)
{
    if(i==0 || j==0)
        return;
    else if(a[i]==b[j])
        {
            PrintSol(i-1,j-1);
            g<<a[i]<<" ";
        }
        else if(c[i][j]==c[i-1][j])
            PrintSol(i-1,j);
            else
                PrintSol(i,j-1);
}

int main()
{
    int m, n, i, j;
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(j=1;j<=n;j++)
        f>>b[j];

    for(i=0;i<=m;i++)
        c[i][0]=0;
    for(j=0;j<=n;j++)
        c[0][j]=0;

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                c[i][j]=1+c[i-1][j-1];
            else
                c[i][j]=Maxim(c[i-1][j], c[i][j-1]);
        }
    g<<c[m][n]<<endl;
    PrintSol(m,n);
    return 0;

}
