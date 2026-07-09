#include<fstream>
using namespace std;
int max(int a, int b)   
{   
    if(a>b)   
      return a;   
   else return b;   
}   
int main()
{int m,n,a[10000],b[10000],k=0,i,j,c[1024][1024],s[1024];   

ifstream f("cmlsc.in");
f>>m>>n;
for(i=1;i<=m;i++) f>>a[i];
for(j=1;j<=n;j++) f>>b[j];
f.close();
 for(i=1;i<=m;i++)   
    for(j=1;j<=n;j++)   
    if(a[i]==b[j])   
    { c[i][j]=c[i-1][j-1]+1; s[++k]=a[i];}   
    else  
    c[i][j]=max(c[i-1][j],c[i][j-1]);
    ofstream g("cmlsc.out");   
      
   g<<c[m][n]<<endl;   
   for(i=1;i<=c[m][n];i++)   
   g<<s[i]<<" ";   
   g.close();   
   return 0;   
     }    

