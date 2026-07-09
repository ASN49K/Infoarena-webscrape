#include <iostream>
#include <algorithm>
int a[1025], b[1025], ab[1025][1025] = { 0 }, i, j, sizeA = 0, sizeB = 0,solution[1025],MAX;

int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	scanf("%d", &sizeA);
	scanf("%d", &sizeB);

	for (i = 0; i < sizeA; i++)	scanf("%d", &a[i]);
	for (i = 0; i < sizeB; i++)	scanf("%d", &b[i]);

	for (i = 0; i < sizeA; ++i)
		for (j = 0; j < sizeB; ++j)
			if (a[i] == b[j])	ab[i+1][j+1] = 1 + ab[i][j];
			else	ab[i + 1][j + 1] = std::max(ab[i][j + 1], ab[i + 1][j]);

	MAX = ab[sizeA][sizeB];
	printf("%d\n", MAX);

	i = sizeA,j = sizeB;

	while (MAX > 0)
	if (ab[i][j] == ab[i - 1][j - 1] + 1 && a[i-1]==b[j-1])	solution[--MAX] = a[i-1], i--, j--;
		else
			if (ab[i][j] == ab[i - 1][j]) i--;
			else j--;

	for (i = 0; i < ab[sizeA][sizeB]; ++i)	printf("%d ", solution[i]);

}