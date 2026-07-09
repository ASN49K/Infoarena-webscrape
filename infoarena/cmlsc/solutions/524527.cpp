#include<stdio.h>
#define dim 1025
using namespace std;

short int D[dim][dim], a[dim], b[dim],n,m,i,j,sir[dim],bst;

int maxim(int a,int b)
{if(a>b)return a;		
return b;}

int main()
{
FILE *f=fopen("cmlsc.in","r"), *g=fopen("cmlsc.out","w");
fscanf(f,"%hd %hd",&n,&m);

for(i=1;i<=n;i++)
	fscanf(f,"%hd",&a[i]);

for(i=1;i<=m;i++)
	fscanf(f,"%hd",&b[i]);

for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)
	{
		if(a[i]==b[j])
			D[i][j]=1+D[i-1][j-1];
		else D[i][j]=maxim(D[i-1][j],D[i][j-1]);	
	}
	
for(i=n,j=m;i,j;)
{
	if(a[i]==b[j])
		sir[++bst]=a[i],i--,j--;
	else if(D[i-1][j]>D[i][j-1])
		i--;
	else j--;
}
fprintf(g,"%hd\n",bst);

for(i=1;i<=bst;i++)
	fprintf(g,"%hd ",sir[i]);
fprintf(g,"\n");
	
fclose(f);
fclose(g);
return 0;
}

