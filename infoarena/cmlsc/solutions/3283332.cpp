#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, A[1025], B[1025],  X[1025], P[1025], sol[1025][1025], p;

int solve(int n, int m, int l){
	if (n > m) return 0;
	if (n == 0 || m == 0) return 0;
	if (A[n] == B[m]) {
		P[l] = A[n];
		sol[n][m] = solve(n-1, m-1, l+1) + 1;
	}  else {
		sol[n][m] = max(solve(n, m-1, l), solve(n-1, m, l));
	}
	return sol[n][m];
}

void s(){
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (A[i] == B[j]) sol[i][j] = 1 + sol[i-1][j-1];
			else sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
		}
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

	s();
	int i = n,  j  =m;
	
	while (i){
		if (A[i] == B[j]){
			P[++p] = A[i];
			i--;
			j--;
		} else if (sol[i-1][j] < sol[i][j-1]){
			j--;
		} else {
			i--;
		}
	}
	 g<< p << endl;
	 while (p){
		 g << P[p] << " ";
		 p--;
	 }


	return 0;
}
