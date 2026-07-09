#include <stdio.h>
#define MAXN 1024
int main()
{
	int comun[MAXN][MAXN];
	int m, n;
	int v1[MAXN], v2[MAXN];
	int solution[MAXN];
	FILE *fin = fopen("cmlsc.in","r");
	FILE *fout =  fopen("cmlsc.out","w");
	int i, j;
	fscanf(fin, "%d%d",&m,&n);
	for (i = 0; i<m; ++i)
		fscanf(fin, "%d", v1+i);
	for (i = 0; i<n; ++i)
		fscanf(fin, "%d", v2+i);
	fclose(fin);
	
	for (i = 0; i<m; ++i)
		for (j = 0; j<n; ++j) {
			if (i == 0)
				comun[i][j] = v1[i] == v2[j]?1:(j > 0?comun[i][j - 1]:0);
			else if (j == 0)
				comun[i][j] = v1[i] == v2[j]?1:comun[i-1][j];
			else 
				if (v1[i] == v2[j])
					comun[i][j] = 1 + comun[i-1][j-1];
				else
					comun[i][j] = comun[i-1][j] > comun[i][j-1]?comun[i-1][j]:comun[i][j-1]; 	
		}
	fprintf(fout,"%d\n", comun[m-1][n-1]);
	i = m - 1;
	j = n - 1;
	int pos = 0;
	while (1) {
		if (comun[i][j] == 1 && v1[i] == v2[j]){
			solution[pos++] = v1[i];
			break;
		}
		if (v1[i] == v2[j]) {
			solution[pos++] = v1[i];
			--i; --j;
		}
		else if (j - 1 < 0)
			--i;
		else if (i - 1 < 0)
			--j;
		else if (comun[i-1][j] > comun[i][j-1])
			--i;
		else
			--j;
	}
	while (pos--) 
		fprintf(fout,"%d ",solution[pos]);
	fprintf(fout,"\n");
	fclose(fout);
	return 0;
}

