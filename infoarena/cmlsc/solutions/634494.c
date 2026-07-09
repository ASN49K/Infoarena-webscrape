#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
  
  return a < b ? b : a;
}

int main()
{
	FILE *f = fopen("cmlsc.in","r");

	int n, m, a[1030], b[1030], d[1030][1030];

	fscanf(f, "%i%i", &n, &m);

	int i, j;

	for (i = 1; i <= n; i++)
		fscanf(f, "%i", a + i);

	for (i = 1; i <= m; i++)
		fscanf(f, "%i", b + i);

	
	
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (a[i] == b[j])
				d[i][j] = 1 + d[i - 1][j - 1];
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		
	int sol[1030], id = -1;

	i = n, j = m;

	while (i != 0 && j != 0)
	{
		if (a[i] == b[j])
		{
			sol[++id] = a[i];
			i--, j--; 
		}
		else
		{
			if (d[i][j-1] < d[i-1][j])
				i--;
			else
				j--;
		}
	}
	
	fclose(f);
	
	f = fopen ("cmlsc.out", "w");
	fprintf(f, "%i\n", id+1);
	for (i = id; i >= 0; i--)
		fprintf(f, "%i ", sol[i]);

	fclose(f);
	return 0;



}
