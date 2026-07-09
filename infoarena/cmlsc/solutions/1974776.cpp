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
	int solutie[1024];
	g << "\n";
	while(mat[i][j] != 0) {
		if(mat[i][j] == mat[i-1][j-1]+1 && a[i] == b[j]) {
			solutie[sol] = a[i];
			i -= 1;
			j -= 1;
			sol--;
		}
		
		else {
			if(mat[i-1][j] > mat[i][j-1]) {
				i--;
			}
			else {
				j--;
			}
		}
	}
	for(int i = 1; i <= mat[m][n]; i++) 
		g << solutie[i] << " ";
	return 0;
}