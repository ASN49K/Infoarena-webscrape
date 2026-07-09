#include<iostream>
#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short x[1025],y[1025],c[1025][1025],m,n,i,j,k,h;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
                     f>>x[i];
    for(i=1;i<=m;i++)
                     f>>y[i];
    
   for(k=1;k<=n;k++)
           for(h=1;h<=m;h++)
                   if (x[k]==y[h])
                      c[k][h]=1+c[k-1][h-1];
                      else 
                      if (c[k-1][h]>c[k][h-1])
                                              c[k][h]=c[k-1][h];
                                              else
                                              c[k][h]=c[k][h-1];
    g<<c[n][m]<<"\n";
    int d[1025];
    for(i=0,k=n,h=m;c[k][h];)
            if (x[k]==y[h])
               {d[i++]=x[k];k--;h--;}
               else 
               if (c[k][h]==c[k-1][h])
                  k--;
                  else 
                  h--;
   for(k=i-1;k>=0;k--) g<<d[k]<<" "; 
    
    
    f.close();
    g.close();
    return 0;
    
    }
