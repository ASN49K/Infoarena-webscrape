#include <fstream>
//#include <iostream>
#define MAX 1025
struct tabela
{
	int lung;
	char sus, st, diag;
} tab[MAX][MAX];
short a[MAX], b[MAX], sol[MAX];
int m, n, nsol;
//a cu m elemente coloane
//b cu n elemente linii
void citeste();
void rezolva();
void traceback();
int main()
{
	citeste();
	rezolva();
	traceback();
}
void traceback()
{
	FILE *fout;
	fout = fopen("cmlsc.out", "w");
	int i=m, j=n;
	nsol = tab[m][n].lung;
	while(tab[i][j].lung)
	{
		if(tab[i][j].diag)
		{
			nsol--;
			sol[nsol] = a[i];
			i--;
			j--;
			continue;
		}
		if(tab[i][j].sus)
		{
			i--;
			continue;
		}
		if(tab[i][j].st)
			j--;
	}
	nsol = tab[m][n].lung;
	fprintf(fout, "%d\n", nsol);
	for(i=0; i<nsol; i++)
		fprintf(fout, "%d ", sol[i]);
}
void rezolva()
{
	int i, j;// m linii cu vectorul a si n coloane cu vectorul b
	for(i=1; i<=m; i++) //i este pt vectorul a
		for(j=1; j<=n; j++)// j este pt vectorul b
			if(a[i]==b[j])
			{
				tab[i][j].lung = 1+tab[i-1][j-1].lung;
				tab[i][j].diag = 1;
			}
			else
			{
				if(tab[i-1][j].lung > tab[i][j-1].lung)
				{
					tab[i][j].lung = tab[i-1][j].lung;
					tab[i][j].sus = 1;
				}
				if(tab[i-1][j].lung < tab[i][j-1].lung)
				{
					tab[i][j].lung = tab[i][j-1].lung;
					tab[i][j].st = 1;
				}
				if(tab[i-1][j].lung == tab[i][j-1].lung)
				{
					tab[i][j].lung = tab[i][j-1].lung;
					tab[i][j].st = 1;
					tab[i][j].sus = 1;
				}
			}
}
void citeste()
{
	int i;
	FILE *fin;
	fin = fopen("cmlsc.in", "r");
	fscanf(fin, "%d %d", &m, &n);
	for(i=1; i<=m; i++)
		fscanf(fin, "%hd", a+i);
	for(i=1; i<=n; i++)
		fscanf(fin, "%hd", b+i);
}
