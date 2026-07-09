#include<iostream>
#include <fstream>
#include <stdio.h>
#define NMax 1024
using namespace std;
int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int A[NMax], B[NMax], n, m, MAX[NMax];
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%d", &A[i]);
	for(int i=1; i<=m; i++)
		scanf("%d", &B[i]);
	int j = 1, z = 1, k = 0;
	for(j=1; j<=n; j++)
		for(z=1; z<=m; z++)
			if(A[j] == B[z])
				MAX[++k] = A[j];
	printf("%d\n", k);
	for(z=1; z<=k; z++)
		printf("%d ", MAX[z]);
	return 0;
}
