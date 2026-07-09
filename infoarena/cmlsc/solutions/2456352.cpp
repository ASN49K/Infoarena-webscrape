#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void lcs(int **rez,int***mat,int len1,int* a,int len2, int* b)
{
	int counter = 0;
	(*mat) = new int* [len2];
	for (int i = 0; i < len2; i++)
		(*mat)[i] = new int[len1];
	for (int i = 0; i < len2; i++)
	{
		for (int j = 0; j < len1; j++)
		{
			if (b[i] == a[j])
			{
				counter++;
				(*mat)[i][j] = counter;
			}
			else
			{
				int max = 0;
				if (i > 0)
					max = (*mat)[i-1][j];
				if (j > 0)
				{
					if ((*mat)[i][j - 1] > max)
						max = (*mat)[i][j-1];
				}
				(*mat)[i][j] = max;
			}

		}
	}
	(*rez) = new int[counter];
}

int main()
{
	FILE* fp = fopen("cmlsc.in", "r");
	int len1, len2;
	fscanf(fp, "%d%d", &len1, &len2);
	int* a = new int[len1];
	for (int i = 0; i < len1; i++)
	{
		fscanf(fp, "%d", &a[i]);
	}
	int* b = new int[len2];
	for (int i = 0; i < len2; i++)
	{
		fscanf(fp, "%d", &b[i]);
	}
	int** mat;
	int* rez;
	lcs(&rez,&mat, len1, a, len2, b);
	int counter = 1;
	for (int i = 0; i < len2; i++)
	{
		for (int j = 0; j < len1; j++)
		{
			if (mat[i][j] == counter)
			{
				rez[counter] = b[i];
				counter++;
				
			}
		}
	}
	delete[] a;
	delete[] b;
	fclose(fp);
	FILE* fout = fopen("cmlsc.out", "w");
	fprintf(fout,"%d\n", counter - 1);
	for (int i = 1; i < counter; i++)
	{
		fprintf(fout,"%d ", rez[i]);
	}

	return 0;

}