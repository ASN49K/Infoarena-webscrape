#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,a[1025],b[1025],A[1025][1025],U[1025][1025],i,j,nr,v[1025],x,y,k;
int  maxim (int x, int y)
{
    if(x>y) return x;
    else return y;
}
int main()
{

    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(j=1;j<=m;j++) f>>b[j];

    for(i=n;i>=1;i--)
        for(j=m;j>=1;j--)
        {
            if(a[i]==b[j])
            {
                A[i][j]=A[i+1][j+1]+1;
            }
            else
                A[i][j]=maxim(A[i][j+1],A[i+1][j] );

        }

    g<<A[1][1];
    g<<endl;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        if(a[i]==b[j]) g<<a[i]<<" ";
    }


 f.close();
 g.close();
    return 0;
}
