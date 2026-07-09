#include <fstream>
#define MAXD 1035
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,k,h,i;
int x[MAXD],y[MAXD],d[MAXD],l[MAXD][MAXD];
int main()
{
 f>>n>>m; 
 for(i=1; i<=n; i++) f>>x[i];
 for(i=1; i<=m; i++) f>>y[i];
 for(k=1; k<=n; k++) l[k][0]=0; for(h=1; h<=m; h++) l[0][h]=0;
 for(k=1; k<=n; k++)
  for(h=1; h<=m; h++)
   if(x[k]==y[h]) l[k][h]=1+l[k-1][h-1];
    else if(l[k-1][h]>l[k][h-1]) l[k][h]=l[k-1][h];
	   else l[k][h]=l[k][h-1];
 g<<l[n][m]<<'\n'; i=0; k=n; h=m;
 while(l[k][h]!=0)
  if(x[k]==y[h]) {i++; d[i]=x[k]; k--; h--;}
   else if(l[k][h]==l[k-1][h])k--; else h--;
 for(k=i; k>0; k--) g<<d[k]<<' ';
 g<<'\n'; g.close(); return 0;
}
