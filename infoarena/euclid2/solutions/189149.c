#include <stdio.h>  

int T;
int x[100001],y[100001],s[100001];

void citire(void)
{
	int i;
	FILE *f=fopen("euclid2.in","r");
	fscanf(f,"%d",&T);
  for(i=0;i<T;i++) fscanf(f,"%d %d",&x[i],&y[i]);
	fclose(f);
}

int cmmdc(int a, int b)
{
	if(b==0) return a;
	return cmmdc(b,a%b);
}

void output(void)
{
	int i;
	FILE *f=fopen("euclid2.out","w");
	for(i=0;i<T;i++) fprintf(f,"%d\n",s[i]);
	fclose(f);
}

int main(void)
{
	int i;
	citire();
	for(i=0;i<T;i++) s[i]=cmmdc(x[i],y[i]);
	output();
	return 0;
} 