#include <cstdio>
using namespace std;

int *sira, *sirb;
int na, nb;
int cml[1025][1025];

int cmlsc() {
	int i,j;

	for (i = 1; i <=na; i++)
		for (j = 1; j<=nb; j++){
			if (sira[i] == sirb[j]) cml[i][j] = cml[i-1][j-1] + 1;
			else cml[i][j] = (cml[i-1][j] > cml[i][j-1])?cml[i-1][j]:cml[i][j-1];
		}

	return cml[na][nb];
}

void printSol(int i, int j) {
	if ((i == 0) || (j == 0)) return;
	if (sira[i] == sirb[j]) {
		printSol(i-1,j-1);
		printf("%d ", sira[i]);
	}
	else
		cml[i-1][j] > cml[i][j-1]?printSol(i-1, j):printSol(i, j-1);
}

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc,out", "w", stdout);
	scanf ("%d %d", &na, &nb);

	sira = new int[na+1];
	sirb = new int[nb+1];

	int i;
	for (i = 1; i <= na; i++)
		scanf("%d ", &sira[i]);

	for (i = 1; i <= nb; i++)
		scanf("%d ", &sirb[i]);

	printf("%d\n", cmlsc());
	printSol(na,nb);
	printf("\n");

	delete []sira;
	delete []sirb;
	return 0;
}