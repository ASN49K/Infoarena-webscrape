#include <iostream>
#include <fstream>
#define maxim(a, b) ((a > b) ? a : b)

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");\

int n,m,i,j,a[1024],b[1024],c[1024][1024],d[1024],k;
       
                           
              

int main()
{   f>>n>>m;
    for(i=1;i<=n;i++)
                     f>>a[i];
    for(j=1;j<=m;j++)
                     f>>b[j];
    for(i=1;i<=n;i++)
                     for(j=1;j<=m;j++)
                     if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
                     else c[i][j]=maxim(c[i-1][j],c[i][j-1]);

    g<<c[n][m]<<"\n";
    i=n;
    j=m;
    while(i>0 && j>0)
              {if(a[i]==b[j])
                              {                             
                                            d[k++]=a[i];
                                            i--;
                                            j--;
                               }
                   else if(c[i-1][j]>c[i][j-1])i--;
                          else j--;
            
              }
    while(k>0)
              {g<<d[k-1]<<" ";k--;}
                     
    f.close();
    g.close();
    system("pause");
}
            
              
