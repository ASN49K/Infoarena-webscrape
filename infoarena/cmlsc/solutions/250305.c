#include <stdio.h>
#include <stdlib.h>
#define MAX 1024


int *lcs(int a[], int b[], int m, int n, int *z)
{
	int i, j, max, v[MAX], maxi = 0, maxj = 0;
	int mat[MAX][MAX];
	
	//process the matrix
	max = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i] == b[j]) 
			{
				//if this is the first row put 1
				if (i == 0 || j== 0)
				{
					mat[i][j] = 1;
				}
				else 
				{
					mat[i][j] = mat[i-1][j-1] + 1;
				}
				if (mat[i][j] > max)
				{
					max = mat[i][j];
					maxi = i;
					maxj = j;
				}
			}
			else {
				if (i == 0 && j == 0)
					mat[i][j] = 0;
				else if (i == 0)
				{
					mat[i][j] = mat[i][j-1];
				} 
				else if (j == 0) 
				{
					mat[i][j] = mat[i-1][j];				
				} else 
				{
					mat[i][j] = mat[i][j-1] > mat[i-1][j] ? mat[i][j-1] : mat[i-1][j];
				}
			}
			//printf("%d ", mat[i][j]);
		}
		//printf("\n");
	}
	//build the matrix
	if (max == 0)
	{
		return NULL;
	}
	*z = max;	
//	printf("After %d\n", *z);
	do
	{
		//find last common element
	//	printf("(%d %d)", maxi, maxj);
	//	printf("%d %d \n", a[maxi], b[maxj]);
		while (mat[maxi][maxj] != max || a[maxi] != b[maxj])
		{			
			if (maxi == 0)
			{
				maxj--;
			} 
			else if (maxj == 0)
			{
				maxi--;
			}
			else 
			{
				if (mat[maxi-1][maxj] > mat[maxi][maxj-1])
				{
					maxi--;
				} 
				else
				{
					maxj--;
				}
			}			
		}
		v[max-1] = a[maxi];
//		printf("%d\n", v[max-1]);
		max--;	
	}
	while (max != 0);/*
	for (i = 0; i < *z; i++)
		printf("%d ", v[i]);
	printf("\n");*/
	return v;
}



int main()
{
	int a[MAX],b[MAX], m, n, i, *rez, z;
	FILE *fin, *fout;
	
	if ((fin = fopen("cmlsc.in", "r")) == NULL)
	{
		printf("Eroare \n");
		exit(-1);
	}
	//read dimension of vectors
	fscanf(fin, "%d%d", &m, &n);

	//read the vectors
	for (i = 0; i<m ; i++)
		fscanf(fin, "%d", &a[i]);
	for (i = 0; i<n ; i++)
		fscanf(fin, "%d", &b[i]);
/*
	for (i = 0; i < m; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n");
*/	rez = lcs(a,b,m,n, &z);		
	
	fout = fopen("cmlsc.out", "w");
	fprintf(fout, "%d\n", z);
	if (z != 0)
	{
		for(i = 0; i < z; i++)
		{
			fprintf(fout, "%d ", rez[i]);
		}
	}
	fclose(fout);
	return 0;
}
