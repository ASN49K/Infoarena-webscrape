#include <iostream>
#include <fstream>
using namespace std;

ifstream in ("cmlsc.in");
ofstream out("cmlsc.out");
int const N=1025;
int x[N],y[N],a[N][N];
int m,n;

void citesc ()
{
    in>>m>>n;
    for(int i=1;i<=m;i++)
        in>>x[i];
    for(int i=1;i<=n;i++)
        in>>y[i];

}
int maxim (int a, int b)
{
    if(a>b)
        return a;
    return b;
}
void construiesc ()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=maxim(a[i-1][j],a[i][j-1]);
        }
}
void refac (int i,int j)
{
    if(i==0||j==0)
        return;
    if(x[i]==y[j])
    {
        refac(i-1,j-1);
        out<<x[i]<<" ";
        return;
    }
    if(a[i-1][j]>a[i][j-1])
    {
        refac(i-1,j);
        return;
    }
    refac(i,j-1);
    return;

}
int main()
{
    citesc();
    construiesc ();
    out<<a[m][n];
    refac(m,n);
    return 0;
}
