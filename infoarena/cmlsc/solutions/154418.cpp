#include<iostream>
#include<fstream>
#define max(a,b) (a>b?a:b)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short c[1025][1025],m,n,i,j,x[1025],y[1025],d[1025],h;
void lungime()
{
     for(i=1;i<=m;i++)
                for(j=1;j<=n;j++)
                   if (x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
                   else c[i][j]=max(c[i-1][j],c[i][j-1]);     
     }
void scrie(int i,int j)
{
     
     for(h=0,i=m,j=n;c[i][j];)
     if (c[i][j]==c[i-1][j-1]+1) {d[++h]=x[i];i--;j--;}
     else 
          if (c[i][j]==c[i-1][j]) i--;
          else j--;
     }

int main()
{
    f>>m>>n;
    for(i=1;i<=m;f>>x[i++]);
        for(i=1;i<=n;f>>y[i++]);
    lungime();
    g<<c[m][n]<<"\n";
    scrie(m,n);
    for(i=h;i>=1;i--)
                     g<<d[i]<<" ";
    f.close();
    g.close();
    return 0;
    }
