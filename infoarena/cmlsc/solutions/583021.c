#include <stdio.h>

#define MAX 1024

int A[MAX], M, B[MAX], N;
int sir[MAX];
int sol[MAX], bst = 0;

int subsir(int nr)
{
	int i, j;

	for (i = 0, j = 0; i < nr && j < N; i++)
		for (; j < N && B[j] != sir[i]; j++)
			;
	return j < N;
}

void back(int nivel, int len)
{
	int i;

	if (nivel == M) {
		if (subsir(len))
			if (len > bst)
			{
				bst = len;
				for (i = 0; i < bst; i++)
					sol[i] = sir[i];
			}
		return;
	}

	back(nivel + 1, len);

	sir[len] = A[nivel]; back(nivel+1, len+1);
}

int main(void)
{
	int i;

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &M, &N);
	for (i = 0; i < M; i++)
		scanf("%d", &A[i]);
	for (i = 0; i < N; i++)
		scanf("%d", &B[i]);

	back(0, 0);

	printf("%d\n", bst);
	for (i = 0; i < bst; i++)
		printf("%d ", sol[i]);

	printf("\n");

	return 0;
}

