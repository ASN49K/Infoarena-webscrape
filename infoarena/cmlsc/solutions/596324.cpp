#include <stdio.h>
#include <stdlib.h>

int SS[1025][1025];  // matricea lungimilor
int m,n;
int *a,*b;

struct Data{
	int dim;
	int *v;
};

int max(int x,int y)
{
	if(x>y)
		return x;
	else
		return y;
}

void Calc(int i,int j)
{	
	if(i==0 || j==0)
		return;
	if(a[i-1] == b[j-1])
	{
		if(SS[i-1][j-1]==-1)
			Calc(i-1,j-1);
		SS[i][j] = 1+SS[i-1][j-1];
	}
	else
	{
		if(SS[i-1][j]==-1)
			Calc(i-1,j);
		if(SS[i][j-1]==-1)
			Calc(i,j-1);
		SS[i][j] =  max(SS[i-1][j],SS[i][j-1]);
	}
}

void CalcSir(int* s,int i,int j)
{
	if(i==0||j==0)
		return;
	if(a[i-1] == b[j-1])
	{
		*s=a[i-1];
		CalcSir(s+1,i-1,j-1);
	}
	else
	{
		if(SS[i-1][j] > SS[i][j-1])
			CalcSir(s,i-1,j);
		else
			CalcSir(s,i,j-1);
	}
}

Data cmlsc()
{
	Data rez;
	Calc(m,n);
	rez.dim = SS[m][n];
	rez.v = (int *)malloc(rez.dim*sizeof(int));
	CalcSir(rez.v,m,n);
	return rez;
}

int main(int argc, char* argv[])
{
	int i,j;
	i=0;
	for(j=0;j<=1024;++j)
		SS[i][j]=0;
	j=0;
	for(i=1;i<=1024;++i)
		SS[i][j]=0;

	for(i=1;i<=1024;++i)
		for(j=1;j<=1024;++j)
			SS[i][j]=-1;

	FILE *fpr = fopen("cmlsc.in","r");
	FILE *fpw = fopen("cmlsc.out","w");

	fscanf(fpr,"%d %d",&m,&n);
	a = (int*)malloc(m*sizeof(int));
	b = (int*)malloc(n*sizeof(int));

	for(i=0;i<m;++i)
		fscanf(fpr,"%d",a+i);
	for(i=0;i<n;++i)
		fscanf(fpr,"%d",b+i);

	Data dt;
	dt = cmlsc();
	
	fprintf(fpw,"%d\n",dt.dim);
	for(i=dt.dim-1;i>=0;--i)
		fprintf(fpw,"%d ",*(dt.v+i));	
		
	fclose(fpr);
	fclose(fpw);
	return 0;
}

