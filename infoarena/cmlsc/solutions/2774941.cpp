#include <iostream>
#include<fstream>
#define l 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[l][l], x[l], y[l], sol[l],k;
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++) f>>x[i];
    for(int i=1; i<=m; i++) f>>y[i];

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=max(a[i-1][j], a[i][j-1]);

    g<<a[n][m]<<"\n";

    int lin=n, col=m;
    while(a[lin][col]!=0)
        if(x[lin]==y[col])
        {
            sol[++k]=x[lin];
            lin--;
            col--;
        }
        else if(a[lin-1][col]==a[lin][col]) lin--;
        else col--;

    for(int i=k; i>=1; i--)
        g<<sol[i]<<" ";
    return 0;
}
