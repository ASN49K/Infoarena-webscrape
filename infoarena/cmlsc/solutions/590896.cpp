#include <fstream>
//#include <iostream>
#define MAX 1025
#define SUS 1
#define ST 2
#define DIAG 4
struct tabela
{
	short lung;
	char mask;
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
		if(tab[i][j].mask&DIAG)
		{
			nsol--;
			sol[nsol] = a[i];
			i--;
			j--;
			continue;
		}
		if(tab[i][j].mask&SUS)
		{
			i--;
			continue;
		}
		if(tab[i][j].mask&ST)
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
				tab[i][j].mask |= DIAG;
			}
			else
			{
				if(tab[i-1][j].lung > tab[i][j-1].lung)
				{
					tab[i][j].lung = tab[i-1][j].lung;
					tab[i][j].mask |= SUS;
				}
				if(tab[i-1][j].lung < tab[i][j-1].lung)
				{
					tab[i][j].lung = tab[i][j-1].lung;
					tab[i][j].mask |= ST;
				}
				if(tab[i-1][j].lung == tab[i][j-1].lung)
				{
					tab[i][j].lung = tab[i][j-1].lung;
					tab[i][j].mask |= ST;
					tab[i][j].mask |= SUS;
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
