#include<stdio.h>
#include<string.h>
int d[124][124],v[124],e[124];
int q[124],k=0;
int main()
{
FILE *f;
FILE *g;
g=fopen("cmlsc.out","wt");
f=fopen("cmlsc.in","rt");
int t=0,a,b;
fscanf(f,"%d",&a);
fscanf(f,"%d",&b);
printf("%d %d\n",a,b);

for(int i=1;i<=a;i++)
	fscanf(f,"%d",&v[i]),d[i][0]=0,printf("%d ",v[i]);
for(int i=1;i<=b;i++){

	fscanf(f,"%d",&e[i]);
	printf("%d  ",e[i]);
	d[0][i]=0;
	
}
d[0][0]=0;
for(int i=1;i<=a;i++)	
{
	for(int j=1;j<=b;j++)
	{
		if(v[i]==e[j])
			d[i][j]=d[i-1][j-1]+1;
		else
			if(d[i-1][j]<d[i][j-1])
				d[i][j]=d[i][j-1];
			else 
				d[i][j]=d[i-1][j];
	}
}
printf("\n");
for(int i=0;i<=a;i++)
	{
	for(int j=0;j<=b;j++)
	printf("%d  ",d[i][j]);
	printf("\n");	
}

for(int i=a,j=b;i;)
	if(v[i]==e[j]) q[k]=v[i]	,i--,j--,k++;
	else if(d[i-1][j]<d[i][j-1])
			j--;
			else
			i--;
	for(int i=0;i<k;i++)
	fprintf(g,"%d ",q[i]);		
	
	
	return 0;
}
