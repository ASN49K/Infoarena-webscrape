#include <stdio.h>

#define L1 1024
#define L2 1024

#define max(a, b) (a > b ? a : b)

int sir1[L1 + 1], sir2[L2 + 1];
int l1, l2; /* lungimile sirurilor, nu imi plac literele m si n in cazul asta*/

int m[L1 + 1][L2 + 1]; //iniatializata deja cu 0

int lungimeCMLSC;

void citesteSiruri()
{
	FILE* fi = fopen("cmlsc.in", "r");
	fscanf(fi, "%d%d", &l1, &l2);
	int i;
	for(i = 1; i <= l1; ++i) fscanf(fi, "%d", &sir1[i]);
	for(i = 1; i <= l2; ++i) fscanf(fi, "%d", &sir2[i]);
	fclose(fi);
}

void determinaMatriceAsociata()
{
	int i, j;
	for(i = 1; i <= l1; ++i)
	{
		for(j = 1; j <= l2; ++j)
		{	
			if(sir1[i] == sir2[j]) m[i][j] = m[i - 1][j - 1] + 1;
			else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
		}
	}
}

void determinaLungime()
{
	lungimeCMLSC = m[l1][l2];
}

void scrieRezultat()
{
	FILE* fo = fopen("cmlsc.out", "w");
	fprintf(fo, "%d\n", lungimeCMLSC);
	fclose(fo);
}

int main()
{
	citesteSiruri();
	determinaMatriceAsociata();
	determinaLungime();
	scrieRezultat();
	return 0;
}

