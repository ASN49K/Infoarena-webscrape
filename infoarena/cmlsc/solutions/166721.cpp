#include<iostream.h>
#include <fstream.h>
ifstream f1("date.in");
ofstream f2("date.out");
struct d
{int x;
 int y;};
d a[100][100];
int i,j,n,m,sir1[100],sir2[100],l,vf[100],nr,k;
int main()
{
f1>>n;
f1>>m;

for(i=1;i<=n;i++)
f1>>sir1[i];
for(i=1;i<=m;i++)
f1>>sir2[i];

for(i=n;i>=1;i--)
    for(j=m;j>=1;j--)
        {
        if(sir1[i]==sir2[j])
        {a[i][j].x=a[i+1][j+1].x+1;a[i][j].y=1;}
        else
             if(a[i+1][j].x>a[i][j+1].x)
                {a[i][j].x=a[i+1][j].x; a[i][j].y=a[i][j].y=0;}
             else
                {a[i][j].x=a[i][j+1].x;a[i][j].y=0;}
        }
l=a[1][1].x;
nr=l;k=0;

/*for(i=1;i<=n;i++)
    {
    for(j=1;j<=m;j++)
    {
       f2<<a[i][j].x<<" ";
    }
    f2<<'\n';
}
f2<<'\n';
for(i=1;i<=n;i++)
    {
    for(j=1;j<=m;j++)
    {
       f2<<a[i][j].y<<" ";
    }
    f2<<'\n';
}
*/
for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
     if((a[i][j].y==1)&(a[i][j].x==nr))
       {k++;
       vf[k]=sir1[i];
       nr--;
       }
f2<<l<<'\n';
for(i=1;i<=l;i++)
    {
    f2<<vf[i]<<' ';
    }
    return 0;
}
