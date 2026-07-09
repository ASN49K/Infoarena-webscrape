#include <stdio.h>
#include <stdlib.h>

int *seq_A, *seq_B, len_A, len_B,
	len_LCS[1025][1025],
	seq_LCS[1024];

inline int max(int a, int b) {
  return a > b ? a : b;
}

int main()
{	
	int i, j, len = 0;
	
	freopen("cmlsc.in","r",stdin);
	scanf("%d %d", &len_A, &len_B);
	seq_A = (int*) malloc( sizeof(int)* (len_A + 1));
	seq_B = (int*) malloc( sizeof(int)* (len_B + 1));
	
	for (i = 1; i <= len_A; i++) {
		scanf("%d", seq_A + i);
	}
	for (i = 1; i <= len_B; i++) {
		scanf("%d", seq_B + i);
	}
	
	//initialize first row
	for (i = 0; i <= len_A; i++) {
		len_LCS[0][i] = 0;
	}
	
	for (j = 1; j <= len_B; j++) {
		len_LCS[j][0] = 0;
		for (i = 1; i <= len_A; i++) {
			if (seq_A[i] == seq_B[j]) {
				len_LCS[j][i] = len_LCS[j-1][i-1] + 1;
			} else {
				len_LCS[j][i] = max (len_LCS[j-1][i], len_LCS[j][i-1]);
			}
		}
	}
	
	for (i = len_A, j = len_B; i && j; ) {
		if (seq_A[i] == seq_B[j]) {
			seq_LCS[++len] = seq_A[i];
			--i;
			--j;
		} else if (len_LCS[j][i-1] > len_LCS[j-1][i]) {
			--i;
		} else {
			--j;
		}
	}
	freopen("cmlsc.out","w",stdout);
	printf("%d\n", len_LCS[len_B][len_A]);
	for ( i = len; i; i--) {
		printf("%d ", seq_LCS[i]);
	}
	return 0;
}
