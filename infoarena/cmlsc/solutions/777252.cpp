#include<iostream>
#include <fstream>
#include <stdio.h>
using namespace std;
int main()
{
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int A[128], B[128], n, m, MAX[256];
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1; i<=n; i++)
		scanf("%d", &A[i]);
	for(int i=1; i<=m; i++)
		scanf("%d", &B[i]);
	int j = 1, z = 1, k = 1;
	for(j=1; j<=n; j++)
		for(z=1; z<=m; z++)
			if(A[j] == B[z])
				MAX[k++] = A[j];
	--k;
	printf("%d\n ", k);
	for(z=1; z<=k; z++)
		printf("%d", MAX[z]);
	return 0;
}
