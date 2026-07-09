
//#include<iostream>
//#include<fstream>
//using namespace std;
//
//int n, m, a[1024], b[1024];
//int L[1024][1024];
//
//
//int max(int a, int b) {
//	return (a > b) ? a : b;
//}
//
//
//int lcs(int n, int m, int a[], int b[]) {
//	
//
//	for (int i = 0; i <= n; i++) {
//		for (int j = 0; j <= m; j++) {
//			if (i == 0 || j == 0)
//				L[i][j] = 0;
//
//			else if (a[i - 1] == b[j - 1])
//				L[i][j] = L[i - 1][j - 1] + 1;
//			else
//				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
//
//		}
//	}
//	return L[n][m];
//}
//
//
//
//
//int main() {
//	
//
//	
//
//	ifstream f("cmlsc.in");
//	ofstream g("cmlsc.out");
//
//	f >> n; f >> m;
//	for (int i = 0; i < n; i++) {
//		f >> a[i];
//	}
//	for (int i = 0; i < m; i++) {
//		f >> b[i];
//	}
//
//	int lung = lcs(n, m, a, b);
//	g << lung<<"\n";	
//	while (n) {
//		if (L[n][m] == L[n - 1][m]+1) {
//			lung--;
//			if (lung) {
//				g << a[n - 1] << " ";
//			}
//			else {
//				g << a[n - 1];
//			}
//		}
//		n -= 1;
//	}
//
//
//	return 0;
//}
//



#include <stdio.h>

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
	int i, j;

	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);

	scanf("%d %d", &M, &N);
	FOR(i, 1, M)
		scanf("%d", &A[i]);
	FOR(i, 1, N)
		scanf("%d", &B[i]);

	FOR(i, 1, M)
		FOR(j, 1, N)
		if (A[i] == B[j])
			D[i][j] = 1 + D[i - 1][j - 1];
		else
			D[i][j] = maxim(D[i - 1][j], D[i][j - 1]);

	for (i = M, j = N; i; )
		if (A[i] == B[j])
			sir[++bst] = A[i], --i, --j;
		else if (D[i - 1][j] < D[i][j - 1])
			--j;
		else
			--i;

	printf("%d\n", bst);
	for (i = bst; i; --i)
		printf("%d ", sir[i]);

	return 0;
}
