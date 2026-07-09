#include<iostream>
#include<fstream>
#include<vector>
#define NMAX 256
#define maxim(a,b) ((a>b)?a:b)

using namespace std;

int LCS[NMAX][NMAX],M[NMAX],N[NMAX],sir[NMAX];

int main(){
	ifstream f("cmlsc.in", ios::in);//Change the name
	ofstream g("cmlsc.out", ios::out);//Change the name

	int lM, lN;
	int aux;

	f >> lM >> lN;
	for (int i = 1; i <= lM; ++i){
		f >> aux;
		M[i]=aux;
	}
	for (int i = 1; i <= lN; ++i){
		f >> aux;
		N[i] = aux;
	}

	for (int i = 1; i <= lM;i++)
	for (int j = 1; j <= lN; j++){
		if (M[i] == N[j])
			LCS[i][j] = LCS[i - 1][j - 1] + 1;
		else LCS[i][j] = maxim(LCS[i - 1][j], LCS[i][j - 1]);
	}


	int i = lM, j = lN;
	int bst = 0;
	while (i){
		if (M[i] == N[j]){
			sir[++bst] = M[i];
			i--;
			j--;
		}
		else if (LCS[i - 1][j] < LCS[i][j - 1]){
			j--;
		}
		else i--;

	}
	g << LCS[lM][lN]<<'\n';
	for (int i = bst; i >0 ; --i){
		g << sir[i] << ' ';
	}

	f.close();
	g.close();
	return 0;
}