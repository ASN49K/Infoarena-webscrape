#include<stdio.h>
#define M 1025
int n,m,a[M],b[M],x[M][M],s[M],r;
void citire()
{int i;
 FILE*f=fopen("cmlsc.in","r");
 fscanf(f,"%d %d",&m,&n);
 for(i=1;i<=m;i++)
	fscanf(f,"%d",&a[i]);
 for(i=1;i<=n;i++)
	fscanf(f,"%d",&b[i]);
 fclose(f);
}
int main()
{int i,j;
 FILE*g=fopen("cmlsc.out","w");
 citire();
 for(i=1;i<=m;i++)
	for(j=1;j<=n;j++)
		if(a[i]==b[j]) x[i][j]=x[i-1][j-1]+1;
		else {x[i][j]=x[i][j-1];
		      if(x[i-1][j]>x[i][j-1]) x[i][j]=x[i-1][j];}
 i=m;
 j=n;
 while(i&&j)
	if(a[i]==b[j]) {s[++r]=a[i];
			i--;
			j--;}
	else if(x[i][j-1]>x[i-1][j]) j--;
	     else i--;
 fprintf(g,"%d\n",r);
 for(i=r;i>=1;i--)
	fprintf(g,"%d ",s[i]);
 fclose(g);
 return 0;
}
