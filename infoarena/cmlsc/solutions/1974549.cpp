#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m,n,a[1025],b[1025];
int mat[1025][1025];

void read() {
	f >> m >> n;
	for(int i = 1; i <= m; i++) {
		f >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		f >> b[i];
	}
}

int main() {

	read();

	for(int i = 0; i <= m; i++) {
		mat[i][0] = 0;
	}

	for(int i = 0; i <= n; i++) {
		mat[0][i] = 0;
	}

	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i] == b[j]) {
				mat[i][j] = mat[i-1][j-1] + 1;
			}
			else {
				mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
			}
		}
	}
	g << mat[m][n];
	
	int sol = mat[m][n];
	int i = m;
	int j = n;
	g << "\n";
	while(sol) {
		if(mat[i][j] == mat[i-1][j-1]+1) {
			g << b[j] << " ";
			i -= 1;
			j -= 1;
			sol--;
		}
		
		else {
			if(mat[i-1][j] > mat[i][j-1]) {
				i -= 1;
			}
			else {
				j -= 1;
			}
		}
	}

	return 0;
}