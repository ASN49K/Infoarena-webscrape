#include <stdio.h>
#define MAX 1025

typedef int sir[MAX];
sir a,b,rez;
int mat[MAX][MAX];
int m,n,i,j,x;

void citeste ()
{
        FILE * in = fopen("cmlsc.in", "r");

	fscanf(in, "%d %d", &m, &n);

        for (i=0; i<m; i++)
        {
                fscanf(in, "%d", &a[i]);
	}

        for (i=0; i<n; i++)
        {
                fscanf(in, "%d", &b[i]);
        }

        fclose(in);
}

void calculeaza()
{
        for (i=1; i<=m; i++)
	{
                for (j=1; j<=n; j++)
                {
                        if (a[i-1] == b[j-1])
                        {
				mat[i][j] = mat[i-1][j-1]+1;
                        }
                        else
                        {
				if (mat[i-1][j] > mat[i][j-1])
                                {
                                        mat[i][j] =  mat[i-1][j];
                                }
				else
                                {
                                        mat[i][j] = mat[i][j-1];
                                }
                        }
                }
        }
}

void afis ()
{
        for (i=0; i<=m; i++)
        {
		for (j=0; j<=n; j++)
                {
			printf("%3d", mat[i][j]);
		}

		printf("\n");
	}
}

void inapoi()
{
	x=1;

	for (i=1; i<=m; i++)
	{
		for (j=1; j<=m; j++)
		{
			if ((mat[i][j] == x) && (a[i-1] == b[j-1]))
			{
				rez[x] = a[i-1];
				x++;
			}
		}
	}
}

void cale()
{
	printf("\n");

	for (i=1; i<x; i++)
	{
		printf("%3d", rez[i]);
	}
}

void scrie ()
{
	FILE * out = fopen("cmlsc.out", "w");

	for (i=1; i<x; i++)
	{
		fprintf(out,"%d ", rez[i]);
	}

	fclose(out);
}

int main ()
{
	citeste();
	calculeaza();
	afis();
	inapoi();
	cale();
	scrie();

        return 0;
}

