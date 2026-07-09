#include <stdio.h>

#define NMAX 1030

short A[NMAX],B[NMAX];
short N,M;
short C[NMAX][NMAX];
short back[NMAX][NMAX];
short v[NMAX];

void citire()
{
	FILE *fin=fopen("cmlsc.in","r");
	
	int i;
	
	fscanf(fin,"%hd %hd",&N,&M);
	
	for(i=1;i<=N;i++)
		fscanf(fin,"%hd",&A[i]);
	for(i=1;i<=M;i++)
		fscanf(fin,"%hd",&B[i]);
	
	fclose(fin);
	
}

void pd()
{
	int i,j;
	for(i=1;i<=N;i++)
		for(j=1;j<=M;j++)
		{
			if (A[i]==B[j]) 
				{
					C[i][j]=1+C[i-1][j-1];
					back[i][j]=1;
				}
			else
			{
				C[i][j]=C[i-1][j];
				back[i][j]=2;
				if(C[i][j-1]>C[i][j]) 
					{
						C[i][j]=C[i][j-1];
						back[i][j]=3;
					}
			}
		}
}

void recons()
{
	int i,j;
	i=N;
	j=M;
	int poz=1;
	while( i!=0 || j!=0 )
	{
		if(back[i][j]==1)
		{
			v[poz]=A[i];
			poz++;
			i--;
			j--;
		}
		
		else if (back[i][j]==2) i--;
			else j--;
		
	}

	
}


void afisare()
{
	FILE *fout=fopen("cmlsc.out","w");
	
	fprintf(fout,"%d\n",C[N][M]);
	
	int i;
	
	for(i=C[N][M];i>=1;i--)
		fprintf(fout,"%d ",v[i]);
}

int main()
{
	citire();
	pd();
	recons();
	afisare();
}
