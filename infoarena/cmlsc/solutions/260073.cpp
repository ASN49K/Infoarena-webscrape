#include<fstream>
#include<iostream>
using namespace std;

int main()
{ int a[102], b[102],m, n, k=0, c[102],i, j;

  ifstream f("cmlsc.in");
    f>>m>>n;
    
   for(i=1;i<=m;i++)
     f>>a[i];
   for(i=1;i<=n;i++)
     f>>b[i];
     f.close();
     for(i=1;i<=m;i++)
       for(j=1;j<=n;j++)
     if(a[i]==b[j])
       c[++k]=a[i];
   
  ofstream g("cmlsc.out");
    g<<k<<endl;
    for(i=1;i<=k;i++) 
     g<<c[i]<<" ";
     g.close();
    

    return 0;
}
