//Infoarena Arhiva Educationala cel mai lung subsir comun 
//Marius Dumitran Februarie 2012
//- Distanta Levenstein O(N^2)

#include<stdio.h>
#include<vector>

using namespace std;
#define maxn (1<<10) 
int Lev[ maxn + 1][ maxn + 1];
int sir1[ maxn + 1], sir2[ maxn + 1];
int Last[ maxn + 1][ maxn + 1];
int main() {
	
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &sir1[i]);
	for (int j = 1; j <= M; ++j)
		scanf("%d", &sir2[j]);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) {
			Lev[i][j] = Lev[i-1][j-1] + (sir1[i] == sir2[j]);
			if (Lev[i][j] < Lev[i-1][j]) 
				Lev[i][j] = Lev[i-1][j], Last[i][j] = 1;
			if (Lev[i][j] < Lev[i][j-1])
				Lev[i][j] = Lev[i][j-1], Last[i][j] = 2;
		}
	printf("%d\n", Lev[N][M]);
	vector <int> solx;
	vector <int> soly;
	int tempx = N, tempy = M;
	while( tempx != 0 && tempy != 0) {
		if( Last[tempx][tempy] == 0) {
			if( sir1[tempx] == sir2[ tempy] ){
				solx.push_back(tempx);
				soly.push_back(tempy);
			}
			tempx -= 1; tempy -= 1; 
			continue;
		}
		if( Last[tempx][tempy] ) {
			tempx -= 1; continue;
		}
		tempy -=1;
	}
	for( int i = solx.size() - 1; i > 0; --i)
		printf("%d ", sir1[solx[i]]);
	printf("%d\n", sir1[solx[0]]);
	return 0;
}
