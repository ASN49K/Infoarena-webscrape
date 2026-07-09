#include <fstream>

using namespace std;

#define DIM 1026

ifstream inFile("cmlsc.in");
ofstream outFile("cmlsc.out");

int X[DIM], Y[DIM];
int M[DIM][DIM];
int n, m;

void print_sequence(int i, int j)
{
	if( M[i][j] = M[i-1][j-1]+1 ){
		print_sequence(i-1, j-1);
		outFile << X[i] << " ";

	}else{
		if( M[i-1][j] > M[i][j-1] ) print_sequence(i-1, j);
		else print_sequence(i, j-1);
	}
}

int main()
{
	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		inFile >> X[i];
	}

	for(int i = 1; i <= m; i++){
		inFile >> Y[i];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if( X[i] = Y[j] ){
				M[i][j] = M[i-1][j-1]+1;
			}else{
				M[i][j] = M[i-1][j] > M[i][j-1] ? M[i-1][j] : M[i][j-1];
			}
		}
	}

	int len = M[n][m];

	outFile << len;


}