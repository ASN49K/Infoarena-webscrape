#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void lcs(int***mat,int len1,int* a,int len2, int* b)
{
	(*mat) = new int* [len2+1];
	for (int i = 0; i <= len2; i++)
		(*mat)[i] = new int[len1+1];
	for (int i = 0; i < len2 + 1; i++)
	{
		(*mat)[i][0] = 0;
	}
	for (int j = 0; j < len1 + 1; j++)
	{
		(*mat)[0][j] = 0;
	}
	for (int i = 1; i < len2+1; i++)
	{
		for (int j = 1; j < len1+1; j++)
		{
			if (b[i-1] == a[j-1])
			{
				(*mat)[i][j] = 1+(*mat)[i-1][j-1];
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
}
void print_lsc(int& counter, int*& rez, int** mat, int len1, int len2, int* a, int* b)
{
	if (len1 ==0 || len2 == 0)
	{
		return;
	}

	else
	{
			if (a[len1-1] == b[len2-1])
			{
				rez[counter++] = a[len1 - 1];
				return print_lsc(counter,rez,mat, len1 - 1, len2 - 1, a, b);
			}
			if(mat[len2][len1-1]>mat[len2-1][len1])
				return print_lsc(counter, rez, mat, len1-1, len2, a, b);
			return print_lsc(counter, rez, mat, len1, len2 - 1, a, b);
	}
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
	lcs(&mat, len1, a, len2, b);
	int counter = 0;
	int* rez = new int[1024];
	print_lsc(counter,rez,mat, len1, len2 , a, b);
	FILE* fout = fopen("cmlsc.out", "w");
	fprintf(fout, "%d\n", counter );
	for (int i = 0; i < counter; i++)
		fprintf(fout,"%d ", rez[counter-i-1]);
	delete[] a;
	delete[] b;
	fclose(fp);
	fclose(fout);
	return 0;

}