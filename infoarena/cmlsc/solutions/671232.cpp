#include <stdio.h>
#include <fstream>

int a[1025];
int b[1025];
int max_c[1025];
int d[1025];

int max;

int is_valid(int index, int size, int m, int n)
{
	for (int i = 0; i < index; i++)
		if (d[i] >= d[index])
			return 0;

	int i1 = 0, j;

	for (int i = 0; i <= index; i++) {
		for (j = i1; j < n; j++) {
			if (b[j] == a[d[i]]) {
				i1 = j;
				break;
			}
		}

		if (j == n)
			return 0;
	}

	return 1;
}

void find_cmlsc(int index, int size, int m, int n)
{
	if (index == size) {
		if (size > max) {
			max = size;
			for (int i = 0; i < size; i++)
				max_c[i] = d[i];
		}
	}

	for (int i = 0; i < m; i++) {
		d[index] = i;
		if (is_valid(index, size, m, n))
			find_cmlsc(index + 1, size, m, n);
	}
}

int main()
{
	int m, n;

	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");

	fin >> m;
	fin >> n;

	for (int i = 0; i < m; i++)
		fin >> a[i];

	for (int i = 0; i < n; i++) 
		fin >> b[i];

	max = 0;


	for (int i = 1; i <= m; i++)
		find_cmlsc(0, i, m, n);

	for (int i = 0; i < max; i++)
		fout << max_c[i] << " ";
	fout << "\n";

	return 0;

}
