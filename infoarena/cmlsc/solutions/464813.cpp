#include <stdio.h>
#define nmax 1025
using namespace std;
int a[nmax],b[nmax],d[nmax][nmax];

int main(void)
{FILE *fin=fopen("cmlsc.in","r");
 FILE *fout=fopen("cmlsc.out","w");
 int sol[nmax],nr=0,i,j,n,m;
 fscanf(fin,"%d%d",&n,&m);
 for(i=1;i<=n;i++) fscanf(fin,"%d",&a[i]);
 for(i=1;i<=m;i++) fscanf(fin,"%d",&b[i]);
 for(i=1;i<=n;i++)
	 for(j=1;j<=m;j++)
		 if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
		 else d[i][j]=(d[i-1][j]>d[i][j-1] ? d[i-1][j]:d[i][j-1]);
 for(i=n,j=m; i && j;)
	 if(a[i]==b[j]) sol[++nr]=a[i],--i,--j;
	 else if(d[i-1][j]>d[i][j-1]) --i;
		 else --j;
 fprintf(fout,"%d\n",nr);
 for(i=nr;i;i--) fprintf(fout,"%d ",sol[i]);
 fclose(fin); fclose(fout);
 return 0;
}
