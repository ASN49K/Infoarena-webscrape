#include<iostream>
#include<fstream>
#define max(a,b) (a>b?a:b)
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short c[1025][1025],m,n,i,j,x[1025],y[1025];
void lungime()
{
     for(i=1;i<=m;i++)
                for(j=1;j<=n;j++)
                   if (x[i]==y[j]) c[i][j]=c[i-1][j-1]+1;
                   else c[i][j]=max(c[i-1][j],c[i][j-1]);     
     }
void scrie(int i,int j)
{
     if (!i||!j) return;
     
     if (c[i][j]==c[i-1][j-1]+1) {scrie(i-1,j-1);g<<x[i]<<" ";}
     else 
          if (c[i][j]==c[i-1][j]) scrie(i-1,j);
          else scrie(i,j-1); 
     }

int main()
{
    f>>m>>n;
    for(i=1;i<=m;f>>x[i++]);
        for(i=1;i<=n;f>>y[i++]);
    lungime();
    g<<c[m][n]<<"\n";
    scrie(m,n);
    f.close();
    g.close();
    return 0;
    }
