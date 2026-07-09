#include <iostream>
#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int v[1030], u[1030], a[1030][1030], sol[1030], vizv[1030], vizu[1030];
int main()
{
    int n, m, i, j, k;
    f>>n;
    f>>m;
    for(i=1; i<=n; i++)
        f>>v[i];
    for(i=1; i<=m; i++)
        f>>u[i];
    for(i=0; i<=m; i++)
        for(j=0; j<=n; j++)
    {
        if(i==0 || j==0)
            a[i][j]=0;
    }
    k=1;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
    {
        if((v[j]==u[i]) && (vizv[j]==0) && (vizu[i]==0))
        {
            a[i][j]=1+a[i-1][j-1];
            sol[k]=v[j]; k++;
            vizv[j]=1; vizu[i]=1;
            cout<<vizv[j]<<" "<<vizu[i]<<"\n";
        }
        else
        {if(a[i-1][j]>a[i][j-1])
        a[i][j]=a[i-1][j];
        else a[i][j]=a[i][j-1];}
    }
    g<<k-1<<"\n";
    for(i=1; i<=k-1; i++)
        g<<sol[i]<<" ";


    return 0;
}
