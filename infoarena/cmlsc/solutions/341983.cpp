#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int A[1025],B[1025],D[1025][1025],sir[1025],N,M;

int main() {
	int i,j;

	freopen("cmlsc.in","r",stdin);
	freopen("cmlsc.out","w",stdout);
	
	scanf("%d%d",&M,&N);
	
	for (i=1;i<=M;++i) scanf("%d",&A[i]);
	for (i=1;i<=N;++i) scanf("%d",&B[i]);
	
	for (i=1;i<=M;++i)
		for (j=1;j<=N;++j)
			if (A[i] == B[j]) D[i][j] = 1 + D[i-1][j-1];
			else D[i][j] = max(D[i-1][j],D[i][j-1]);
	
	i = M, j = N;
	int l = 0;
	
	while (i != 0) {
		if (A[i] == B[j]) sir[++l] = A[i] , --i , --j;
		else if (D[i-1][j] < D[i][j-1]) --j;
		else --i;
	}
	
	printf("%d\n",l);
	for (i=l;i>0;--i) printf("%d ",sir[i]);
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
