#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
///				de lungime, se termina in
int n, m, A[1025], B[1025],  X[1025], P[1025];
int sol[1025][1025];


int solve(int n, int m, int l){
	if (n > m) return 0;
	if (n == 0 || m == 0) return 0;
	if (sol[n][m]) return sol[n][m];
	if (A[n] == B[m]) {
		P[l] = A[n];
		sol[n][m] = solve(n-1, m-1, l+1) + 1;
	}  else {
		sol[n][m] = max(solve(n, m-1, l), solve(n-1, m, l));
	}
	return sol[n][m];

}

int main() {
	f >> n >> m;

	for (int i = 1; i <= n; i++){
		f >> A[i];
	}

	for (int i = 1; i <= m; i++){
		f >> B[i];
	}

	if ( n > m) {
		swap(A,B);
		swap(n,m);
	}
	int l = solve(n,m,1) ;
	g << l << endl;
	for (int i = l; i > 0; i--){
		g << P[i] << " ";

	}

	return 0;
}
