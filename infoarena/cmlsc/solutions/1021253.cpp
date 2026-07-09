#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int a[1025],b[1025],m,n,d[1025][1025],sir[1026],bst=0;
int maxim(int x,int y)
{
    return ((x<y) ? y:x);
}
void citire()
{int i;
 f>>n>>m;
 for(i=1;i<=n;i++) f>>a[i];
 for(i=1;i<=m;i++) f>>b[i];}
int main()
{int i,j;
 citire();
 for(i=1;i<=n;i++)
  for(j=1;j<=m;j++)
   if(a[i]==b[j]) d[i][j]=1+d[i-1][j-1];
   else d[i][j]=maxim(d[i][j-1],d[i-1][j]);
 i=n; j=m;
 while(i!=0)
 {if(a[i]==b[j]) {sir[++bst]=a[i]; i--; j--;}
  else if(d[i-1][j]<d[i][j-1]) j--;
  else i--;}
 for(i=bst;i>=1;i--) g<<sir[i]<<" ";



      return 0;
}
