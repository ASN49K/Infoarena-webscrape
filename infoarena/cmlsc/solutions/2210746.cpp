#include<iostream>
#include<string>
#include<fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int max(int a, int b) {
	if(a > b)
		return a;
	return b;
}

string backtrack(int i, int j, string a, int **mat, int *A) {
	while (true) {
		if (mat[i][j] == 0)
			return a;
		while (mat[i - 1][j] == mat[i][j])
				i--;
		while (mat[i][j - 1] == mat[i][j])
				j--;
		a = to_string(A[i]) + " " + a;
		i = i - 1;
		j = j - 1;
	}
}

int main() {
	int *A, *B, M, N;
	f >> M >> N;
	A = new int[M];
	B = new int[N];
	for (int i = 1; i <= M; i++)
		f >> A[i];
	for (int j = 1; j <= N; j++)
		f >> B[j];
	int **mat = new int*[M+1];
	for (int i = 0; i <= M; i++)
		mat[i] = new int[N+1];

	for (int i = 0; i <= M; i++)
		mat[0][i] = 0;
	for (int i = 0; i <= M; i++)
		mat[i][0] = 0;

	/*for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;*/

	for (int i = 0; i <= M; i++)
		for (int j = 0; j <= N; j++)
			if ((i == 0) || (j == 0))
				mat[i][j] = 0;
			else if (A[i] == B[j])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else if (A[i] != B[j])
				mat[i][j] = max(mat[i][j - 1], mat[i - 1][j]);

	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	int i = M;
	int j = N;
	string a = "";

	string b = backtrack(i, j, a, mat, A);
	g << mat[i][j] << endl;
	g << b;

	return 0;
}