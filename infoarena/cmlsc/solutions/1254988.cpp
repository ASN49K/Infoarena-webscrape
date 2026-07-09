#include "stdio.h"

FILE *f, *g;
char m[1025][1025];
int N, M;
char a[1025], b[1025];

void solve() 
{
	for(int i = 1; i <= N; i++)
		for(int j = 1; j <= M; j++)
			if(a[i] == b[j])
				m[i][j] = 1 + m[i-1][j-1];
			else if(m[i-1][j] > m[i][j-1])
				m[i][j] = m[i-1][j];
			else 
				m[i][j] = m[i][j-1];
}

void display_solution(int i, int j)
{
	if(m[i][j] > 0)
	{
		if(a[i] == b[j])
		{
			display_solution(i-1,j-1);
			fprintf(g, "%d ", a[i]);
		}
		else 
		{
			if(m[i][j] == m[i-1][j])
				display_solution(i-1,j);
			else if(m[i][j] == m[i][j-1])
				display_solution(i, j-1);
		}
	}
}

int main()
{
	f = fopen("cmlsc.in", "r");
	g = fopen("cmlsc.out", "w");

	fscanf(f, "%d", &N);
	fscanf(f, "%d", &M);

	for(int i = 1; i <= N; i++)
		fscanf(f, "%d", &a[i]);

	for(int i = 1; i <= M; i++)
		fscanf(f, "%d", &b[i]);

	solve();
	fprintf(g, "%d\n", m[N][M]);
	display_solution(N, M);

	fclose(f);
	fclose(g);

	return 0;
}