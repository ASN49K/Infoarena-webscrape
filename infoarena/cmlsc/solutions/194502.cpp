#include <stdio.h>

#define IN "cmlsc.in"
#define OUT "cmlsc.out"

#define MAXN 100

int n,m,A[MAXN],B[MAXN];

int M[MAXN][MAXN], Rez[MAXN][MAXN][2];


FILE *f2;

void read()
{
	FILE *f=fopen(IN,"r");
	fscanf(f,"%d %d",&n,&m);
	for (int i=1;i<=n;i++)
		fscanf(f,"%d",&A[i]);

	for (int i=1;i<=m;i++)
		fscanf(f,"%d",&B[i]);
	

	fclose(f);
}

void printare(int n,int m)
{
	if (n>=0 && m>=0 && Rez[n][m][0] && Rez[n][m][1])
	{
		printare(Rez[n][m][0],Rez[n][m][1]);
	}

	if (A[n] == B[m])
		fprintf(f2,"%d ",A[n]);
}

void solve()
{
	f2=fopen(OUT,"w");
	
	int i,j;

	M[0][1]=M[1][0]=M[0][0]=0;
	
	for (i=0;i<2;i++)
		Rez[0][1][i]=Rez[1][0][i]=Rez[0][0][i]=0;

	for (i=1;i<=n;i++)
		for (j=1;j<=m;j++)
		{
			M[i][j] = M[i-1][j-1] + (A[i] == B[j]);
			Rez[i][j][0] = i-1;
			Rez[i][j][1] = j-1;

			if (M[i][j-1] > M[i][j])
			{
				M[i][j] = M[i][j-1];
				Rez[i][j][0] = i;
				Rez[i][j][1] = j-1;
			}
			if (M[i-1][j] > M[i][j])
			{
				M[i][j] = M[i-1][j];
				Rez[i][j][0] = i-1;
				Rez[i][j][1] = j;
			}
		}
	

	fprintf(f2,"%d\n",M[n][m]);
	printare(n,m);
	fprintf(f2,"\n");

	fclose(f2);
}

int main()
{
	read();
	solve();	
	return 0;
}
