#include<fstream>
#include<iostream>
using namespace std;

int n, m, i, j, a[1024], b[1024],k,c[1024][1024],d[1024];
void citire()
{
     ifstream f("cmlsc.in");
         f>>m>>n;
         
     for(i=1;i<=m;i++)
         f>>a[i];
     for(j=1;j<=n;j++)
        f>>b[j];
        
     f.close();
}

int max(int a, int b)
{
    if(a>b)
       return a;
    else return b;
}

void construire()
{
     k=0;
 
 for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
     if(a[i]==b[j])
        {
          k++;
          c[i][j]=c[i-1][j-1]+1;
          d[k]=a[i];
         }
      else
         c[i][j]=max(c[i-1][j], c[i][j-1]);
 
}
        
void afisare()
{
     ofstream g("cmlsc.out");
        g<<c[m][n]<<"\n";
     
     for(i=1;i<=k;i++)
        g<<d[i]<<" ";
       }
int main()
{
    citire();
    construire();
    afisare();
    return 0;
}
