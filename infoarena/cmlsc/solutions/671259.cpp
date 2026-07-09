#include <stdio.h>
#include <stdint.h>
#include <fstream>

uint32_t a[1025];
uint32_t b[1025];
uint32_t d[1025];
uint32_t max_c[1025];
uint32_t matrix[1025][1025];
uint8_t directions[1025][1025];

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

void find_cmlsc_small_bkt(int index, int size, int m, int n)
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
			find_cmlsc_small_bkt(index + 1, size, m, n);
	}
}

void find_cmlsc_bkt(int m, int n)
{
	for (int i = 1; i <= m; i++)
		find_cmlsc_small_bkt(0, i, m, n);
}

void find_cmlsc_dyn(int m, int n)
{
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0) {
				matrix[i][j] = 0;
				continue;
			}

			if (a[i - 1] == b[j - 1]) {
				matrix[i][j] = 1 + matrix[i - 1][j - 1];
				directions[i][j] = 0;
			}
			else {
				if (matrix[i][j - 1] > matrix[i - 1][j]) {
					matrix[i][j] = matrix[i][j - 1];
					directions[i][j] = 1;
				} else {
					matrix[i][j] = matrix[i - 1][j];
					directions[i][j] = 2;
				}
			}
		}
	}


	max = matrix[m][n];
	int i = m, j = n, index = max - 1;
	while (i > 0 && j > 0) {
		switch (directions[i][j])
		{
		case 0:
			d[index] = i - 1;
			index--;
			i--;
			j--;
			break;

		case 1:
			j--;
			break;
		case 2:
			i--;
			break;
		default:
			break;
		}
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

	find_cmlsc_dyn(m, n);

	fout << max << "\n";
	for (int i = 0; i < max; i++) 
		fout << a[d[i]] << " ";
	fout << "\n";

	return 0;

}
