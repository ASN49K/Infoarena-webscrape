#include<iostream>
#include<fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
void print(char **b, int *a, int i, int j){
	if (i == 0 || j == 0) return;
	else 
	if (b[i][j] == 'd') {
		print(b, a, i - 1, j - 1);
		g << a[i]<<" ";
	}
	else 
	if (b[i][j] == 'v') print(b, a, i, j - 1);
	else print(b, a, i - 1, j);
}


int main()
{
	int n, m, i, j = 0;
	f >> n >> m;
	int *a = new int[n + 1];
	int *b = new int[m + 1];
	for (i = 1; i <= m; i++) f >> a[i];
	for (j = 1; j <= n; j++) f >> b[j];
	int **mat = new int*[m + 1];
	char **matt = new char*[m + 1];
	for (i = 0; i <= m; i++){
		mat[i] = new int[n + 1];
		matt[i] = new char[n + 1];
	}
	for (i = 0; i <= m; i++) mat[i][0] = 0;
	for (j = 0; j <= n; j++) mat[0][j] = 0;

	for (i = 1; i <= m; i++)
	for (j = 1; j <= n; j++){
		if (a[i] == b[j]){
			mat[i][j] = mat[i - 1][j - 1] + 1;
			matt[i][j] = 'd';
		}
		else if (mat[i][j - 1] > mat[i - 1][j]){
			mat[i][j] = mat[i][j - 1];
			matt[i][j] = 'v';
		}
		else {
			mat[i][j] = mat[i - 1][j];
			matt[i][j] = 'n';
		}
	}
	for (i = 0; i <= m; i++){cout << endl;
	for (j = 0; j <= n; j++)
		cout << matt[i][j];
	}
	g << mat[m][n] << endl;
	print(matt, a, m, n);
	
	
	

	//cin.get();
	f.close();
	g.close();
	return 0;
}
