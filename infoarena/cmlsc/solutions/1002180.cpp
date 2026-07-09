#include <iostream>
using namespace std;
int M, N;
int B[1025];
int A[1025];
int sol[1025][1025];
int maxSol = 0;

int max(int a, int b) {
	if (a>b) return a;
	else	 return b;
}

int main(void) {
	cin >> M >> N;

	for (int i=1; i<=M; i++)
		cin >> A[i];
	for (int i=1; i<=N; i++)
		cin >> B[i];

	for (int i=1; i<=M; i++)
		for (int j=1; j<=N; j++) {
			int curSol = max(sol[i-1][j], sol[i][j-1]);
			if (A[i]==B[j])
				curSol = max(curSol, sol[i-1][j-1]+1);
			sol[i][j] = curSol;
			maxSol = max(curSol, maxSol);
		}

	cout << "\n";
	for (int i=0; i<=M; i++) {
		for (int j=0; j<=N; j++)
			cout << sol[i][j] << "\t";
		cout << "\n";
	}

	return 0;
}
