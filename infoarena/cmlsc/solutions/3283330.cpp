#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
///				de lungime, se termina in
int n, m, A[1025], B[1025],  X[1025], P[1025];


int solve(int n, int m, int l){
	if (n > m) return 0;
	if (n == 0 || m == 0) return 0;
	if (A[n] == B[m]) {
		P[l] = A[n];
		return solve(n-1, m-1, l+1) + 1;
	} 
	return max(solve(n, m-1, l), solve(n-1, m, l));
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
