#include <iostream>
#include <fstream>

using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
int v[1024], u[1024], a[1024][1024], sol[1024];
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
    {
        a[i][0]=0;
    }
    for(j=0; j<=n; j++)
        a[0][j]=0;
    k=1;
    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
        cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
    {
        if((v[j]==u[i]))
        {
            a[i][j]=1+a[i-1][j-1];
        }
        else
        {if(a[i-1][j]>a[i][j-1])
        a[i][j]=a[i-1][j];
        else a[i][j]=a[i][j-1];}
        cout<<a[i][j]<<" ";
    }
    cout<<"\n";
    }
    i=m;
    j=n;
    while (i>=0 && j>=0)
    {
        if(a[i][j-1]!=a[i][j] && a[i-1][j]!=a[i][j])
        {
            sol[k]=u[i];
            i--; j--; k++;
        }
        else
        {
            if(a[i-1][j]==a[i][j])
                i--;
            else
                j--;
        }

    }
    g<<k-1<<"\n";
    for(i=k-1; i>=1; i--)
        g<<sol[i]<<" ";

    return 0;
}
