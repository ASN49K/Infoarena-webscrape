#include<fstream>
#include<iostream>
using namespace std;

long n, m, a[1025], b[1025],k,c[1025][1025],d[10025];

void citire()
{
     int i, j;
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
     int i, j,s,ok;
     k=0;
 
 for(i=1;i<=m;i++)
   for(j=1;j<=n;j++)
     if(a[i]==b[j])
        {
          
          c[i][j]=c[i-1][j-1]+1;
          for(s=1;s<=k;s++)
             if(d[s]==a[i])
               {
                 ok=0;break;
                 }
             if(ok)
              {
                 k++;
                 d[k]=a[i];
              }
               
         }
      else
         c[i][j]=max(c[i-1][j], c[i][j-1]);
 
}
        
void afisare()
{
     int i;
     ofstream g("cmlsc.out");
        g<<c[m][n]<<endl;
     
     for(i=1;i<=k;i++)
        g<<d[i]<<" ";
     g.close();  
       }
       
int main()
{
    citire();
    construire();
    afisare();
    return 0;
}
