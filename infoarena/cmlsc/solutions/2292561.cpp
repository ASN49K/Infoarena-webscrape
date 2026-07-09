#include <iostream>
#include <climits>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int nmax=1030;

int a[nmax], b[nmax], cmlsc[nmax][nmax], maxim[nmax];

void drum(int i, int j) {
	if(!i || !j) return;
	if( a[i] == b[j]) {
		drum(i - 1, j - 1);
		fout << a[i] << ' ';
	} else if(cmlsc[i - 1][j] > cmlsc[i][j - 1]) {
		drum(i - 1, j);
	} else {
		drum(i, j - 1);
	}
}

int main(){
	int m, n;
	fin >> m >> n ;
	for(int i=1; i <= m; i++){
		fin >> a[i];
	}
	for(int j=1;j <= n;j++){
		fin >> b[j];
	}

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(a[i]==b[j]) cmlsc[i][j]=cmlsc[i-1][j-1]+1;
			else cmlsc[i][j]=max(cmlsc[i-1][j],cmlsc[i][j-1]);
		}
	}

	fout<<cmlsc[m][n]<<'\n';
	drum(m, n);

	/*int i = m;
	int j = n;
	int k = 0;
	while(i != 0 && j != 0) {
		if (a[i] == b[j]) {
			++ k;
			maxim[k] = a[i];
			i --;
			j --;
		} else {
			if(cmlsc[i - 1][j] > cmlsc[i][j-1]){
				i--;
			}else{
				j--;
			}
		}
	}*/

	return 0;
}