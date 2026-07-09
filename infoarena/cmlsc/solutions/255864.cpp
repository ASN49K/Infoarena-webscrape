#include<stdio.h>
int m, n;
int a[1024];
int b[1024];
int aux[1024];
int pos[1024];

void afis(FILE *f, int p)
{
	if (p == -1) return;
	afis(f, pos[p]);
	fprintf(f, "%d ", b[p]);
}
int main()
{
	FILE* in = fopen("cmlsc.in", "rt");
	fscanf(in, "%d %d", &m, &n);
	//scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		fscanf(in, "%d", &a[i]);
		//scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		fscanf(in, "%d", &b[i]);
		//scanf("%d", &b[i]);
	fclose(in);
	for (int i = 0; i < m; i++)
	{
		int max = 0;
		int p = -1;
		for (int j = 0; j < n; j++)
			if (a[i] == b[j])
			{
				aux[j] = max + 1;
				pos[j] = p;
			}
			else if (aux[j] > max)
			{
				max = aux[j];
				p = j;
			}
	}
	int max = 0;
	int p = 0;
	for (int i = 0; i < n; i++)
		if (aux[i] > max)
		{
			p = i;
			max = aux[i];
		}
	FILE* out = fopen("cmlsc.out", "wt");
	fprintf(out, "%d\n", aux[p]);
	afis(out, p);
	fclose(out);
}