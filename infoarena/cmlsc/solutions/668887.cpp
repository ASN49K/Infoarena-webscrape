#include<stdio.h>
FILE *f=fopen("cmlsc.in","r"), *g=fopen("cmlsc.out","w");
int a[1025], b[1025], c[1025], n, m,cnt;
void cit()
{
	fscanf(f,"%d %d", &n, &m);
	for(int i=1;i<=n;i++)
		fscanf(f,"%d", &a[i]);
	for(int i=1;i<=m;i++)
		fscanf(f,"%d", &b[i]);
}

void rez()
{
	for(int i=1;i<=n;i++)
	{
		int sw=0;
		for(int j=1;j<=m;j++)
			if(a[i]==b[j])
			{
				cnt++;
				c[i]=c[i-1]+1;
				sw=1;
				break;
			}
		if(!sw) 
			c[i]=c[i-1];
	}
}

void tip()
{
	fprintf(g,"%d\n", cnt);
	for(int i=1;i<=n;i++)
		if(c[i]>c[i-1])
			fprintf(g,"%d ", a[i]);
}
int main()
{
	cit();
	rez();
	tip();
	return 0;
}
