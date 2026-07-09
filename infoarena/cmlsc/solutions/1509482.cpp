#include <bits/stdc++.h>
#define NMax 1030
#define pb push_back
#define po pop_back

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m;
int A[NMax], B[NMax];
int M[NMax][NMax];
vector<int> solution;

/**
 * [CHECKED] Helping function for getting the max between two ints
 */
inline int maxim(int a, int b) {
	if (a > b)
		return a;
	return b;
}

/**
 * [CHECKED] Helping function for getting the min between two ints
 */
inline int minim(int a, int b) {
	return a+b-maxim(a,b);
}

/**
 * [CHECKED] Reading the input
 */
void read() {
	f>>n>>m;
	for (int i=1;i<=n;i++)
		f>>A[i];
	for (int j=1;j<=m;j++)
		f>>B[j];
}

/**
 * [CHECKED] Outputing the solutions vector
 */
void outputSolution() {
	g<<endl;
	sort(solution.begin(), solution.end());
	for (vector<int>::iterator it = solution.begin(); it != solution.end(); ++it)
		g<<*it<<' ';
}

/**
 * Function for finding the solution of the input with the help of DP in reverse
 */
void findSolution() {
	int i = n, j = m;
	while (i >= 1 && j >= 1) {
		if (M[i][j] == 1+M[i-1][j-1] && A[i] == B[j]) {
			solution.pb(A[i]);
			i--; j--;
		} else {
			if (M[i-1][j] > M[i][j-1])
				i--;
			else
				j--;
		}
	}
	
	outputSolution();
}

/**
 * [CHECKED] DP applied on the input read
 */
void solve() {
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			if (A[i] == B[j])
				M[i][j] = maxim(maxim(M[i-1][j], M[i][j-1]), 1+M[i-1][j-1]);
			else
				M[i][j] = maxim(M[i-1][j], M[i][j-1]);
		}
	}
	
	g<<M[n][m];
	
	findSolution();
}

/**
 * [CHECKED] Starting the program
 */
int main() {
	
	read();
	solve();
	
	f.close(); g.close();
	return 0;
}
