#include<stdio.h>
#include<string.h>
int d[1024][1024],v[1024],e[1024];
int q[1024],k=0;
int main()
{
FILE *f;
FILE *g;
g=fopen("cmlsc.out","wt");
f=fopen("cmlsc.in","rt");
int a,b;
fscanf(f,"%d",&a);
fscanf(f,"%d",&b);
if(a==0||b==0)
 fprintf(g,"0");

for(int i=1;i<=a;i++)
	fscanf(f,"%d",&v[i]),d[i][0]=0;
for(int i=1;i<=b;i++){

	fscanf(f,"%d",&e[i]);
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


for(int i=a,j=b;i;)
	if(v[i]==e[j]) q[k]=v[i]	,i--,j--,k++;
	else if(d[i-1][j]<d[i][j-1])
			j--;
			else
			i--;
			fprintf(g,"%d \n",k);
	for(int i=k-1;i>=0;i--)
	fprintf(g,"%d ",q[i]);		
	
	
	return 0;
}
