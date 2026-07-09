#include <iostream>
#include <fstream>
using namespace std;
fstream f;
int x[2000],y[2000], t[2000][2000],sol[2000];
int i,j,n,m,pozj,pozint;
main()
{
    f.open("cmlsc.in",ios::in);
    f>>n>>m;
    for (i=0;i<n;i++)
    {
        f>>x[i];
        t[i+1][0]=x[i];
    }
    for (i=0;i<m;i++)
    {
        f>>y[i];
        t[0][i+1]=y[i];
    }

    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
        if (x[i-1]==y[j-1]) t[i][j]=1;

    }
    for (i=0;i<=n;i++){
    for (j=0;j<=m;j++)
    cout<<t[i][j]<<" ";
    cout<<endl;
    }
    int k=0;
    for (i=1;i<=n;i++)
    for (j=1;j<=m;j++)
    {
        if (t[i][j]==1 && j>pozj && j>pozint){
        sol[k]=t[i][0];
        k++;
        pozint=pozj;
        pozj=j;
        j=m+1;
        }
        if (t[i][j]==1 && j<pozj && j>pozint)
        {
            sol[k-1]=t[i][0];
            pozj=j;
            j=m+1;
        }
    }
    cout<<endl;
    for (i=0;i<k;i++)
    {
        cout<<sol[i]<<" ";
    }
    f.close();
    f.open("cmlsc.out",ios::out);
    f<<k<<endl;
    for (i=0;i<k;i++)
    f<<sol[i]<<" ";
}
