#include<iostream>
#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int m,n,a[1030],b[1030],d[1030][1030],u,R[1030];
struct tata
{
    int x,y;
}r[1030][1030];
int main()
{
    in>>m>>n;
    int i,j;
    for(i=1;i<=m;i++) in>>a[i];
    for(i=1;i<=n;i++) in>>b[i];
    a[++m]=257;
    b[++n]=258;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
            {
                d[i][j]=d[i-1][j-1]+1;
                r[i][j].x=i-1;
                r[i][j].y=j-1;
            }
            else
            {
                if(d[i][j-1]>d[i-1][j])
                {
                    d[i][j]=d[i][j-1];
                    r[i][j].x=i;
                    r[i][j].y=j-1;
                }
                else
                {
                    d[i][j]=d[i-1][j];
                    r[i][j].x=i-1;
                    r[i][j].y=j;
                }
            }
        }
    out<<d[m][n]<<'\n';
    i=m,j=n;
    int c1,c2;
    while(i && j)
    {
        //cout<<r[i][j].x<<' '<<r[i][j].y<<'\n';
        if(a[r[i][j].x]==b[r[i][j].y]) R[++u]=a[r[i][j].x];
        c1=r[i][j].x;
        c2=r[i][j].y;
        i=c1,j=c2;
    }
    for(i=u;i>0;i--) out<<R[i]<<' ';
}
