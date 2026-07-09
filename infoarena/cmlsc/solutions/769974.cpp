#include <stdio.h>
#include <vector>
#define NMax 1025

FILE * f;
FILE * g;

int n, m, a[NMax], b[NMax];
int cost[NMax][NMax];
std::vector<int> rez;

void read();
void resolve();
void write();

int max(int a, int b) { return (a > b ? a : b); }

int main()
{
	read();
	resolve();
	write();

	return 0;
}

void write()
{
	int i, max = -1;

	// check the maximum
	for (i=0; i<=n; i++)
	{
		if (cost[m][i] > max)
		{
			max = cost[m][i];
		}
	}

	// print the maximum to the file
	fprintf(g, "%d\n", max);

	for (i=0; i < rez.size(); i++)
	{
		fprintf(g, "%d ", rez[i]);
	}

	fprintf(g, "\n");
	fclose(g);
}

void resolve()
{
	int i, j;
	

	for (j=0; j<m; j++)
	{
		for (i=0; i<n; i++)
		{
			// check if equal
			if (a[i] == b[j])
			{
				cost[j+1][i+1] += 1;
				rez.push_back(a[i]);
			}
			
			cost[j+1][i+1] += max(cost[j][i+1], cost[j+1][i]);
		}
	}
}

void read()
{
	int i;

	f = fopen("cmlsc.in", "rt");
	g = fopen("cmlsc.out", "wt");

	// read the array size
	fscanf(f, "%d %d", &n, &m);

	// read the first array
	for (i=0; i<n; i++)
	{
		fscanf(f, "%d", &a[i]);
	}

	// read the second array
	for (i=0; i<m; i++)
	{
		fscanf(f, "%d", &b[i]);
	}

	// close the file
	fclose(f);
}