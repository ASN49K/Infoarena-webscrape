//
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
FILE *f=fopen("cmlsc.in","r"),*g=fopen("cmlsc.out","w");

int n1,n2, v1[1025], v2[1025],i,j,t[1025][1025],d[1025],k;

void read()
{
	fscanf(f,"%d %d", &n1,&n2);

	for(i=1;i<=n1;i++)
		fscanf(f,"%d",&v1[i]);

	for(i=1;i<=n2;i++)
		fscanf(f,"%d",&v2[i]);
}

int max(int a, int b)
{
	if(a>=b)
		return a;
	else
		return b;


}


void reconstruct()
{
	k=1;
	i=n1;
	j=n2;
	while(i)
	{
		if(v1[i]==v2[j])
		{
			d[k++]=v1[i];
			i--;
			j--;

		}

		else
			if(t[i-1][j]>t[i][j-1])
				i--;
			else
				j--;
	}

	for(i=k-1;i>=1;i--)
		fprintf(g,"%d ",d[i]);
}



void solve_dynamic()
{
	for(i=1;i<=n1;i++)
		for(j=1;j<=n2;j++)
		{
			if(v1[i]==v2[j])
				t[i][j]=t[i-1][j-1]+1;
			else
				t[i][j]=max(t[i-1][j],t[i][j-1]);
		}

fprintf(g,"%d\n",t[n1][n2]);
reconstruct();

}


int main()
{
	read();
	solve_dynamic();
	return 0;

}