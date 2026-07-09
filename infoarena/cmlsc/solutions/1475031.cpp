#include <cstdio>
#include <algorithm>

#define DIM 1024
#define INF ((1LL<<31)-1)

using namespace std;

int N, M, Len, Len2, posi, posj;
int A[DIM], B[DIM], S[DIM];
int D[DIM][DIM];

int main(){

	//freopen("cmlsc.in" ,"r", stdin );
	//freopen("cmlsc.out","w", stdout);

	scanf("%d %d", &N, &M);

	for(int i = 1; i <= N; i ++)
		scanf("%d", &A[i]);

	for(int i = 1; i <= M; i ++)
		scanf("%d", &B[i]);

	for(int i = 1; i <= N; i ++)
		for(int j = 1; j <= M; j ++)
			if(A[i] == B[j])
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max(D[i-1][j], D[i][j-1]);
	Len = D[N][M]; Len2 = Len; posi = N; posj = M;

	printf("%d\n", Len);

	while(posi != 0 && posj != 0){

		if(A[posi] == B[posj]){

			S[Len--] = A[posi];
			posi --;
			posj --;

		} else {

			if(D[posi][posj] == D[posi-1][posj] && posi != 1) posi --;
			else                                              posj --;
		}
	}

	for(int i = 1; i <= Len2; i ++)
		printf("%d ", S[i]);

	fclose(stdin );
	fclose(stdout);

	return 0;
}
