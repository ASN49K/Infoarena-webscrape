#include <iostream>
#include <fstream.h>
using namespace std;
fstream g;
void backtrack( int C[300][300], int x[300],int y[300], int i,int j)
{
    if (i == 0 || j == 0);
    else if ( x[i] == y[j])
        {backtrack(C, x, y, i-1, j-1); g<<x[i]<<" ";}
    else
        if (C[i][j-1] > C[i-1][j])
            backtrack(C, x, y, i, j-1);
        else
            backtrack(C, x, y, i-1, j);
}
int main()
{
    int n,m,C[300][300],x[300],y[300],i,j;
    fstream f;
    f.open("cmlsc.in",ios::in);
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];

    for (i=0;i<=n;i++)
       C[i][0]=0;
    for (j=0;j<=m;j++)
       C[0][j]=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (x[i] == y[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = max(C[i][j-1], C[i-1][j]);

    g.open("cmlsc.out",ios::out);
    g<<C[n][m]<<endl;
    backtrack(C,x,y,n,m);
}
