#include<iostream>
#include <stdio.h>
#include <math.h>
#include <queue>
using namespace std;
int n, m, a[256], b[256], S[256][256], indici[256], k, st[256];
void citire()
{
	FILE* f = fopen("cmlsc.in", "r");
	fscanf(f, "%d %d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		fscanf(f, "%d", &a[i]);
	}
	for(int i=1; i<=m; i++)
	{
		fscanf(f, "%d", &b[i]);
	}
	fclose(f);
}
void subsircomun()
{
	for (int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if (a[i] == b[j])
			{
				S[i][j] = S[i-1][j-1] + 1;
			}
			else
			{
				if(S[i-1][j] > S[i][j-1])
					S[i][j] = S[i-1][j];
				else
					S[i][j] = S[i][j-1];
			}
		}
	}
}
/*void afisare()
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
			cout<<S[i][j]<<" ";
		cout<<endl;
	}
	cout<<S[n][m]<<endl;
	for(int i=1; i<=k; i++)
		cout<<indici[i]<<" ";
}*/
void drum()
{
	int i = n, j = m;
	k = 0;
	while (i && j)
	{
		if(S[i][j] == S[i-1][j-1] + 1 && a[i] == b[j])
		{
			st[++k] = a[i];
			i--;
			j--;
		}
		else
			if(S[i-1][j] > S[i][j-1])
				i--;
			else
				j--;
	}
	FILE *g = fopen("cmlsc.out", "w");
	fprintf(g, "%d\n", S[n][m]);

	for (int i = k; i>=1; i--)
	{
		fprintf(g, "%d ", st[i]);
	}
	fclose(g);
}
int main()
{
	citire();
	subsircomun();
	//afisare();
	drum();
	return 0;
}