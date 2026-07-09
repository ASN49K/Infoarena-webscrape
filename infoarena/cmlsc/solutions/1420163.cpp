#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 1024

struct _LCS {
	int val;
	char dir;
};

int a[MAX], b[MAX], subsir[MAX];
_LCS lcs[MAX + 1][MAX + 1];

int main() {
	int m, n, top = 0;
	// freopen("cmlsc.in", "r", stdin);
	// freopen("cmlsc.out", "w", stdout);
	scanf("%d%d", &m, &n);
	for(int i = 0; i < m; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &b[i]);
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {

			if(a[i] == b[j]) {
				lcs[i+1][j+1].val = lcs[i][j].val + 1;
				lcs[i+1][j+1].dir = 0;
			}

			else {
				lcs[i+1][j+1].val = lcs[i][j+1].val > lcs[i+1][j].val ? lcs[i][j+1].val : lcs[i+1][j].val;
				if(lcs[i+1][j].val > lcs[i][j+1].val) {
					lcs[i+1][j+1].dir = 1;
				}

				else if(lcs[i+1][j].val < lcs[i][j+1].val) {
					lcs[i+1][j+1].dir = -1;
				}

				else {
					lcs[i+1][j+1].dir = 2;
				}

			}
		}
	}

	for(int i = m, j = n; lcs[i][j].val != 0;) {
		switch(lcs[i][j].dir) {

			case 0:
				subsir[top++] = a[i-1];
				--i;
				--j;
				break;

			case 1:
				--j;
				break;

			case -1:
				--i;
				break;

			case 2:
				-- i;
				break;
		}
	}
	
	printf("%d\n", top);
	for(int i = top - 1; i >= 0; --i)
		printf("%d ", subsir[i]);
	printf("\n");

	return 0;
}