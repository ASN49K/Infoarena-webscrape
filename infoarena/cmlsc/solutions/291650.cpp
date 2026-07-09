#include<fstream.h>   
int sir[1025],bst=0,c[1025][1025];   
int maxim(int d,int e)   
 {   
  if(d>e)   
   return d;   
    else  
     return e;   
 }   
void ver(int a[1025],int b[1025],int m,int n)   
{ int i,j;   
 for(i=1;i<=m;i++)   
  for(j=1;j<=n;j++)      
    if (a[i] == b[j])      
      c[i][j] = 1 + c[i-1][j-1];      
       else     
             c[i][j] = maxim(c[i-1][j], c[i][j-1]);      
    i=m;   
    j=n;   
    while(i)      
    if (a[i] == b[j])      
      {sir[++bst] = a[i];   
    --i;   
     --j;   
     }      
        else if (c[i-1][j] < c[i][j-1])      
            --j;      
        else     
            --i;      
    ofstream g("cmlsc.out");   
    g<<bst<<"\n";     
  
    for (i = bst; i; --i)      
       g<<sir[i]<<" ";   
}   
int main()   
{   
int i,j,n,m,a[1024],b[1024];   
ifstream f("cmlsc.in");   
f>>n>>m;   
for(i=1;i<=n;i++)   
 f>>a[i];   
for(j=1;j<=m;j++)   
 f>>b[j];   
  ver(a,b,n,m);   
return 0;   
} 