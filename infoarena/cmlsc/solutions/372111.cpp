#include<stdio.h>
#define dim 1030
using namespace std;

short int a[dim],b[dim],mat[dim][dim],sol[dim],n,m,i,j,k,man;

int maxim(short int x, short int y)
{if(x>y) return x;
return y;}

int main()
{
 FILE *f=fopen("cmlsc.in","r"), *g=fopen("cmlsc.out","w");
 
fscanf(f,"%hd%hd",&n,&m);
 for(i=1;i<=n;i++)
 fscanf(f,"%hd",&a[i]);
 
 for(i=1;i<=m;i++)
 fscanf(f,"%hd",&b[i]);
 
 for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
 if(b[i]==a[j]) 
	 {mat[i][j] = mat[i-1][j-1]+1; man=mat[i][j];}
 else 
	 mat[i][j] = maxim (mat[i-1][j] , mat[i][j-1]);
 
 for(i=n;i>=1;i--)
for(j=m;j>=1;j--)
if(a[i]==b[j] && mat[j][i]==man) {k++; sol[k]=a[i]; man--;}

fprintf(g,"%hd\n",k);
for(i=k;i>=1;i--)
fprintf(g,"%hd ",sol[i]); fprintf(g,"\n");

fclose(f);
fclose(g);
return 0;
}
