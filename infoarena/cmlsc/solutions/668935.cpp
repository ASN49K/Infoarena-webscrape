#include<stdio.h>
FILE *f=fopen("cmlsc.in","r"), *g=fopen("cmlsc.out","w");
int a[1025], b[1025], c[1025][1025], n, m,cnt;
void cit()
{
	fscanf(f,"%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		fscanf(f,"%d", &a[i]);
	for(int i=1;i<=m;i++)
		fscanf(f,"%d", &b[i]);
}

int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

void rez()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
				c[i][j]=c[i-1][j-1]+1;
			else 
				c[i][j]=max(c[i-1][j], c[i][j-1]);
}


void backtrace(int i, int j)
{
	if( i && j)
	{
		if(a[i]==b[j])
		{
			backtrace(i-1,j-1);
			fprintf(g,"%d ", a[i]);
		}
		else 
			if(c[i-1][j]>c[i][j-1])
				backtrace(i-1,j);
			else 
				backtrace(i, j-1);
	}
}

void tip()
{
	fprintf(g,"%d\n", c[n][m]);
	backtrace(n,m);
}

int main()
{
	cit();
	rez();
	tip();
	return 0;
}
