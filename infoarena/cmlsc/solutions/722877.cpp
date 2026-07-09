#include <cstdio>
#include <iostream>
#define UP 1
#define LEFT 2
#define DIAG 3

short M,N;
short i,j;
short **auxc,**auxb;
short *a,*b;
FILE *in = fopen("cmlsc.in","r");
FILE *out = fopen("cmlsc.out","w");

void print(short m, short n)
{
	if (m==0 || n==0)
		return;
	if (auxb[m][n] == DIAG)
	{
		print(m-1,n-1);
		fprintf(out,"%hd ",a[m]);
	}
	else if (auxb[m][n] == UP )
		print(m-1,n);
	else
		print(m,n-1);
}

int main()
{
	

	
	fscanf(in,"%hd %hd",&M,&N);
	a=new short[M+1];
	b=new short[N+1];
	
	for(i=1;i<=M;i++)
		fscanf(in,"%hd",&a[i]);
	for(i=1;i<=N;i++)
		fscanf(in,"%hd",&b[i]);
	fclose(in);

	auxc = new short*[M+1];
	auxb = new short*[M+1];
	for(i=0;i<M+1;i++)
	{
		auxc[i] = new short[N+1];
		auxb[i] = new short[N+1];
	}


	for(i=1;i<=M;i++)
		auxc[i][0]=0;
	for(i=0;i<=N;i++)
		auxc[0][i]=0;


	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(a[i]==b[j])
			{
				auxc[i][j] = auxc[i-1][j-1]+1;
				auxb[i][j]=DIAG;
			}
			else if (auxc[i-1][j] >= auxc[i][j-1])
			{
				auxc[i][j] = auxc[i-1][j];
				auxb[i][j]=UP;
			}
			else 
			{
				auxc[i][j]=auxc[i][j-1];
				auxb[i][j]=LEFT;
			}
		}
	}
	fprintf(out,"%hd\n",auxc[M][N]);
	print(M,N);
	
	return 0;

}