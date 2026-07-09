#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

#define NMax 1050

int n, m;
int x[NMax], y[NMax];
int c[NMax][NMax];

void init();
void rezolvare();
void afisare(int, int);

int main(){
	init();
	rezolvare();
	fout << c[n][m] << '\n';
	afisare(n, m);
}

void init(){
	int i;
	fin >> n >> m;
	for(i = 1; i <= n; i++) fin >> x[i];
	for(i = 1; i <= m; i++) fin >> y[i];
}

void rezolvare(){
	int i, j;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(x[i] == y[j]) c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = max(c[i - 1][j], c[i][j - 1]);
}

void afisare(int i, int j){
	if(i == 0 || j == 0) return;
	if(c[i - 1][j] == c[i][j]) afisare(i - 1, j);
	else if(c[i][j - 1] == c[i][j]) afisare(i, j - 1);
	else{
		afisare(i - 1, j - 1);
		fout << x[i] << ' ';
	}
}
