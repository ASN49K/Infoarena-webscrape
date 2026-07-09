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
          c[i][j]=c[i-1][j-1]+1;
      else
         c[i][j]=max(c[i-1][j], c[i][j-1]);
 
}
        
void afisare()
{
     ofstream g("cmlsc.out");
        g<<c[m][n]<<"\n";
        
     i=m;j=n;
     while(i) 
    {     
          if(a[i]==b[j])         
    
    { 
             d[++k]=a[i]; 
             i--; 
             j--; 
         } 
         else 
            if(c[i][j-1]>c[i-1][j]) 
                 j--; 
         else 
            i--; 
}
   for(i=c[m][n];i>=1;i--)
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
