#include <fstream>
using namespace std;
int M, N;
int B[1025], A[1025];
int sol[1025][1025];
int maxSol = 0, maxI, maxJ;
int sir[1024];

int max(int a, int b) {
	if (a>b) return a;
	else	 return b;
}

int main(void) {
	ifstream in; in.open("cmlsc.in");
	in >> M >> N;

	for (int i=1; i<=M; i++)
		in >> A[i];
	for (int i=1; i<=N; i++)
		in >> B[i];

	for (int i=1; i<=M; i++)
		for (int j=1; j<=N; j++) {
			int curSol = max(sol[i-1][j], sol[i][j-1]);
			if (A[i]==B[j])
				curSol = max(curSol, sol[i-1][j-1]+1);
			sol[i][j] = curSol;
			if (curSol > maxSol) {
				maxSol = curSol;
				maxI = i; maxJ = j;
			}
		}

	int i=maxSol; while (i>0) {

		if (sol[maxI-1][maxJ] == sol[maxI][maxJ]) {
			maxI -= 1;
		}
		else if (sol[maxI][maxJ-1] == sol[maxI][maxJ]) {
			maxJ -= 1;
		}
		else {
			i--; sir[i] = A[maxI];
			maxI -= 1; maxJ -= 1;
		}
	}

	ofstream out; out.open("cmlsc.out");
	out << maxSol << "\n";
	for (int i=0; i<maxSol; i++)
		out << sir[i] << " ";

	return 0;
}
