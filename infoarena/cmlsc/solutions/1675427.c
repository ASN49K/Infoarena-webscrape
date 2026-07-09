#include <stdio.h>

enum {
	ALMAX = 1025,
	BLMAX = 1025
};

static int al, bl, a[ALMAX], b[BLMAX], mat[ALMAX][BLMAX];

static int Max(int x, int y)
{
	return x > y ? x : y;
}

static void Build(void)
{
	int i, j;
	for (i = 1; i <= al; ++i) {
		for (j = 1; j <= bl; ++j) {
			if (a[i] == b[j]) {
				mat[i][j] = mat[i - 1][j - 1] + 1;
			} else {
				mat[i][j] = Max(mat[i - 1][j], mat[i][j - 1]);
			}
		}
	}
}

static void Read(void)
{
	int i;
	scanf("%i%i", &al, &bl);
	for (i = 1; i <= al; ++i) {
		scanf("%i", &a[i]);
	}
	for (i = 1; i <= bl; ++i) {
		scanf("%i", &b[i]);
	}
}

static void Print(void)
{
	int i, j, slen, sir[ALMAX];
	i = al;
	j = bl;
	slen = 0;
	printf("%i\n", mat[i][j]);
	while (i != 0 && j != 0) {
		if (a[i] == b[j]) {
			sir[slen++] = a[i];
			--i;
			--j;
		} else if (mat[i - 1][j] > mat[i][j - 1]) {
			--i;
		} else {
			--j;
		}
	}
	for (i = slen - 1; i >= 0; --i) {
		printf("%i ", sir[i]);
	}
	printf("\n");
}

int main(void)
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	Read();
	Build();
	Print();
	return 0;
}
