#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m,i,j;
int a[1050], b[1050];
int matr[1050][1050];

void afisare(int i, int j){
	if(i == 0 || j == 0) return;
	if(matr[i - 1][j] == matr[i][j]) afisare(i - 1, j);
	else if(matr[i][j - 1] == matr[i][j]) afisare(i, j - 1);
	else{
		afisare(i - 1, j - 1);
		g << a[i] << ' ';
	}
}


int main(){

	f >> n >> m;
	for(i = 1; i <= n; i++) f >> a[i];
	for(i = 1; i <= m; i++) f >> b[i];


    	for(i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(a[i] == b[j]) matr[i][j] = matr[i - 1][j - 1] + 1;
			else matr[i][j] = max(matr[i - 1][j], matr[i][j - 1]);

	g << matr[n][m] << '\n';
	afisare(n, m);
}





