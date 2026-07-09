#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int N=1025;
int a[N][N],x[N],y[N],n,m;
void construiesc()
{
    int i,j;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(x[i]==y[j])
               a[i][j]=1+a[i-1][j-1];
            else
            {
                if(a[i-1][j]>a[i][j-1])
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=a[i][j-1];
            }
        }
    return;
}

void refac(int i,int j)
{
    if (i==0 || j==0) return;
    if(x[i]==y[j])
    {
        refac(i-1,j-1);
        out<<x[i]<<" ";
        return;
    }
    if(a[i-1][j]>a[i][j-1])
        {refac(i-1,j);
        return;}
    else
        {refac(i,j-1);
        return;}
}
int main()
{
    int i;
    in>>m>>n;
    for(i=1;i<=m;i++)
        in>>x[i];
    for(i=1;i<=n;i++)
        in>>y[i];
    construiesc();
    out<<a[m][n]<<"\n";
    refac(m,n);
    return 0;
}
