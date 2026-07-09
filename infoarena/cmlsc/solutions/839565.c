/**
 * Sa se determine subsirul de lungime maxima care apare atat in A cat si in B.
 * Restrictii:
 * 1 ≤ M, N ≤ 1024
 * Numerele din cei doi vectori nu depasesc 256
 */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int v[MAX], a[MAX], b[MAX], poz[MAX], *p1, *p2, lc, found = 0;
FILE* out;

void printsol(int n)
{
	fprintf(out, "%d\n", n);
	int i;
	for (i=0; i<n; i++)
	{
		fprintf(out, "%d ", p2[v[i]]);
	}
	found = 1;
}


int findpoz(int k, int l)
{
	int start;
	if (l == 0) start = 0;
	else start = poz[l-1];
	int i;
	for (i = start; i < lc; i++)
	{
		if (p1[i] == p2[k]) return i;
	}
	return -1;
}

void back(int l, int k, int n)
{
	if (found == 1) return;
	
	if (l == k) printsol(k);
	else 
	{
		int j = (l == 0 ? 0 : v[l-1] + 1);
		int i;
		for (i = j; i<n; i++)
		{
			v[l] = i;
			poz[l] = findpoz(i, l);
			if (poz[l] != -1) back(l+1, k, n);
		}
	}
}


int main()
{
	int a1[MAX], nr[256], x, i; 
	for (i=0; i<256; i++)
		nr[i] = 0;
	
	int n, m;
	FILE* in = fopen("cmisc.in", "r");
	out = fopen("cmisc.out", "w");
	x = fscanf(in, "%d %d", &n, &m);
	for (i = 0; i<n; i++)
	{
		int r = fscanf(in, "%d", &x);
		nr[x] = 1;
		a1[i] = x;
	}
	
	int m2 = 0;
	for (i = 0; i<m; i++)
	{
		int r = fscanf(in, "%d", &x);
		if (nr[x] == 1) 
		{
			b[m2] = x;
			m2++;
			nr[x] = 2;
		}
	}
	
	int n2 = 0;
	for (i = 0; i<n; i++)
	{
		if (nr[a1[i]]==2)
		{
			a[n2] = a1[i];
			n2++;
		}
	}
	
	/*
	for (int i = 0; i<n2; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	for (int i = 0; i<m2; i++)
	{
		printf("%d ", b[i]);
	}
	*/
	
	int min;
	if (n2 < m2) {
		min = n2;
		p1 = b;
		p2 = a;
		lc = m2;
	}
	else { 
		min = m2;
		p1 = a;
		p2 = b;
		lc = n2;
	}
	
	for (i = min; i > 1; i--)
	{
		back(0, i, min);
		printf("\n");
	}
	
	
	fclose(in); fclose(out);
	return 0;
}
