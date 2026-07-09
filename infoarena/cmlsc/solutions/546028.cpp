#include <stdio.h>
#define LIM 1025
FILE *f=fopen("cmlsc.in", "r"), *g=fopen("cmlsc.out", "w");
int i, j, m, n, t=1, a[LIM], b[LIM], v[LIM][LIM], rez[LIM];

void citeste()
{
	fscanf(f, "%d%d", &m, &n);
	for (i=1;i<=m;i++)
		fscanf(f, "%d", &a[i]);
	for (i=1;i<=n;i++)
		fscanf(f, "%d", &b[i]);
}

void matrice()
{
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)
		{
			if (a[i]==b[j])
				v[i][j]=v[i-1][j-1]+1;
			else
				if (v[i-1][j]>v[i][j-1])
					v[i][j]=v[i-1][j];
				else
					v[i][j]=v[i][j-1];
		}
}

void reconstituie(int m, int n)
{
	if (v[m-1][n]||v[m][n-1])
	{
		if (v[m-1][n]<v[m][n]&&v[m][n-1]<v[m][n])
			rez[t++]=a[m];
		if (v[m-1][n]>v[m][n-1])
			reconstituie(m-1, n);
		else
			reconstituie(m, n-1);
	}
	else
		rez[t]=a[m];
}

void tipareste()
{
	fprintf(g, "%d\n", v[m][n]);
	for (i=t;i>0;i--)
		fprintf(g, "%d ", rez[i]);
	fclose(f);
	fclose(g);
}

int main()
{
	citeste();
	matrice();
	reconstituie(m, n);
	tipareste();
	return 0;
}