// https://www.infoarena.ro/problema/cmlsc

#include<fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int A[1025], B[1025];

// Rezolvam problema utilizand tehnica programarii dinamice.

// Definirea starii (a subproblemei):
// dp[i][j] - lungima maxima a subsirului comun atunci cand luam in considerare doar primele i numere din A, respectiv primele j numere din B. 

// Parcurgem vectorii A si B, folosind indicii i, respectiv j.

// Pentru fiecare pereche (i, j), verificam daca A[i] este egal cu B[j].

// Daca A[i] este egal cu B[j], atunci extindem un subsir comun optim, construind solutia pe baza subproblemei dp[i-1][j-1].
// Astfel, dp[i][j] = dp[i-1][j-1] + 1.

// In caz de inegalitate, verificam cum putem obtine o solutie mai buna, fie luand in considerare mai departe pe A[i], fie pe B[j] 
// (alegem maximul dintre cele doua posibilitati).
// Astfel, dp[i][j] = max(dp[i-1][j], dp[i][j-1]).

// Cazurile de baza, cu care initializam matricea dp, sunt:
// dp[0][i] = 0, pentru oricare i (daca primul sir nu are niciun element, subsirul comun nu are nici el niciun element)
// dp[i][0] = 0, pentru oricare i (daca al doilea sir nu are niciun element, atunci nici subsirul comun nu are niciun element)
// Aceste initialziari sunt realizate implicit, declarand tabloul global.

// Solutia o gasim la dp[n][m], adica lungimea maxima a subsirului luand in considerare toate elementele din A, respectiv din B.

// Complexitate: O(n * m) (timp + spatiu)
// Daca nu reconstruim solutia, spatiul poate fi optimizat la O(min(n, m)),
// deoarece recurența dp[i][j] depinde doar de linia anterioara din matrice.
// Totusi, in acest caz nu mai putem reconstrui subsirul comun.

int dp[1025][1025];

int main() {
	fin >> n >> m;

	for(int i = 1; i <= n; i++) {
		fin >> A[i];
	}

	for(int j = 1; j <= m; j++) {
		fin >> B[j];
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				if(dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}

	fout << dp[n][m] << "\n";

	// in vectorul sol adaugam elementele ce fac parte din subsirul comun
	int sol[1024];
	int lenSol = 0;
	int i = n, j = m;

	// construim subsirul comun de lungime maxima, folosind backtracking 
	while(i >= 1 && j >= 1) {
		if(A[i] == B[j]) {
			sol[lenSol++] = A[i];
			i--;
			j--;
		} else if(dp[i - 1][j] > dp[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}

	// am construit solutia invers, asadar o afisam de la lenSol spre 0
	for(int k = lenSol - 1; k >= 0; k--) {
		fout << sol[k] << " ";
	}

	fout << "\n";

	fin.close();
	fout.close();

	return 0;
}
