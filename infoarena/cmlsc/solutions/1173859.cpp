#include <vector>
#include <cstdio>
#include <climits>

using namespace std;

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
	FILE *input = fopen("cmlsc.in", "r");
	FILE *output = fopen("cmlsc.out", "w");
#else
	FILE *input = fopen("input.txt", "r");
	FILE *output = stdout;
#endif

vector < vector<int> > V;
vector <int> A, B;
int N, M;


void show(int x, int y);

int main() {

	int i, j;
	
	fscanf(input, "%d %d", &N, &M);
	A.resize(N);
	B.resize(M);
	for(i = 0; i < N; ++i) {
		fscanf(input, "%d", &A[i]);
	}

	for (i = 0; i < M; ++i) {
		fscanf(input, "%d", &B[i]);
	}
	
	V.resize(N + 1, vector <int> (M + 1));
	
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j) {
			if (A[i] == B[j]) {
				V[i + 1][j + 1] = V[i][j] + 1;
			}
			else {
				V[i + 1][j + 1] = max(V[i][j], max(V[i + 1][j], V[i][j + 1]));
			}
		}
	}
	
	
//	for (i = 0; i <= N; ++i) {
//		for (j = 0; j <= M; ++j) {
//			printf("%d ", V[i][j]);
//		}
//		printf("\n");
//	}

	fprintf(output, "%d\n", V[N][M]);
	show(N, M);

	
	
	
	fclose(input);
//#ifdef ONLINE_JUDGE
	fclose(output);
//#endif
	return 0;
}

void show(int x, int y) {
	//printf("%d %d\n", x, y);
	if (x == 0 || y == 0) {
		return;
	}
	int nx, ny;
	
	if (A[x - 1] == B[y - 1]) {
		nx = x - 1;
		ny = y - 1;
		show(nx, ny);
		fprintf(output, "%d ", A[nx]);
	}
	else {
		nx = x - 1;
		ny = y;
		if (V[x - 1][y - 1] > V[nx][ny]) {
			ny = y - 1;
		}
		if (V[x][y - 1] > V[nx][ny]) {
			nx = x;
			ny = y - 1;
		}
		show (nx, ny);
	}
}
