#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b)	( (a)<(b) ? (b) : (a) )

int M, N, *a, *b, **save;

void initialise() {
	int i;

	scanf("%d%d", &M, &N);

	a = calloc(M, sizeof(int));
	b = calloc(N, sizeof(int));
	save = calloc(M+1, sizeof(int));
	for (i = 0; i < M+1; ++i)
		save[i] = calloc(N+1, sizeof(int));

	/* read arrays from file */
	for (i = 0; i < M; ++i)
		scanf("%d", a+i);
	for (i = 0; i < N; ++i)
		scanf("%d", b+i);
}

void freeAll() {
	free(a);
	free(b);
	int i;
	for (i = 0; i < M+1; ++i)
		free(save[i]);
	free(save);
}

/* Save in save[i][j] = max{ save[i-1][j], save[i][j-1] },
 * where save[i][j] is the maximum length from a[0..i-1] and
 * b[0..j-1].
 */
void preprocess() {
	int i, j;

	for (i = 1; i < M+1; ++i)
		for (j = 1; j < N+1; ++j)
			if ( a[i-1] == b[j-1] ) {
				save[i][j] = 1 + save[i-1][j-1];
			} else {
				save[i][j] = MAX ( save[i-1][j], save[i][j-1] );
			}
}

void writeSequence() {
	/* maximum length */
	int maxLength = save[M][N];
	printf("%d\n", maxLength);

	/* no reason to continue */
	if (maxLength == 0)
		return;

	/* build a maximum sequence, based on the 2D array
	 */
	int *maxSequence = calloc(maxLength, sizeof(int));
	int i = M, j = N;
	while ( save[i][j] != 0 )
		if ( a[i-1] == b[j-1] )
			maxSequence[--maxLength] = b[j-1], --i, --j;
		else if ( save[i][j-1] < save[i-1][j] )
			i--;
		else
			j--;

	/* print Sequence */
	printf("%d", maxSequence[0]);
	for (i = 1; i < save[M][N]; ++i)
		printf(" %d", maxSequence[i]);
	putchar('\n');
	
	free(maxSequence);
}

int main() {
	if ( !freopen("cmlsc.in2", "r", stdin) ) {
		fprintf(stderr, "File cmlsc.in does not exist. Exiting.\n");
		return 1;
	}
	freopen("cmlsc.out", "w", stdout);

	initialise();
	preprocess();
	writeSequence();
	freeAll();
	return 0;
}
