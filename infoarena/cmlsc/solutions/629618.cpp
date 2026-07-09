#include <cstdio>
#include <algorithm>
#include <vector>

int k ,m, n, i, j, x, A[1050], B[1050];
int s1[1050], s2[1050], *LV, *LN, *AUX;

int main()
{
	FILE * iFile;
	FILE * oFile;
	
	iFile = fopen("cmlsc.in", "r");
	oFile = fopen("cmlsc.out", "w");	
	
	
	fscanf(iFile, "%d %d", &n, &m);
	
	for(i=0;i<n;i++)
	{
		fscanf(iFile, "%d", &x);
		A[i] = x;
	}
	for(i=0;i<m;i++)
	{
		fscanf(iFile, "%d", &x);
		B[i] = x;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(A[i] == B[j])
			{
				s1[k] = B[j];
				k++;
			}
		}
	}
	fprintf(oFile, "%d\n", k);
	for(j=0;j<k;j++)
	{
		fprintf(oFile, "%d ", s1[j]);
	}
	

	fclose(iFile);
	fclose(oFile);	
	return 0;
}
