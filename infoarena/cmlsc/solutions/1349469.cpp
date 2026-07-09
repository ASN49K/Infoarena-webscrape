#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],A[1025][1025],U[1025][1025],i,j,nr,v[1025],x,y;
int main()
{

    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(j=1;j<=m;j++) f>>b[j];


    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
        {
        if(a[i]==b[j])A[i][j]=1+A[i+1][j+1],U[i][j]=1;
        else

        {
            if(A[i][j+1]>A[i+1][j])A[i][j]=A[i][j+1],U[i][j]=2;
            else A[i][j]=A[i+1][j],U[i][j]=3;
        }
        }

    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(U[i][j]==1)nr++,v[nr]=a[i];

    g<<nr<<endl;

    for(i=1;i<=nr;i++)
        g<<v[i]<<' ';
 f.close();
 g.close();
    return 0;
}
