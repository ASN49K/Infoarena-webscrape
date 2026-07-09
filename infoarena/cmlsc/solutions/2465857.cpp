#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int const nmax = 1024;

int a[nmax], b[nmax], cmlsc[nmax][nmax], n, m;

void drum(int m, int n){
	if(m == 0 || n == 0){
		return;
	}
	if(a[m] == b[n]){
		drum(m-1, n-1);

		fout << a[m] << " ";
	}
	else if( cmlsc[m-1][n] > cmlsc[m][n-1]){
		drum(m-1, n);
	}else{
		drum(m, n-1);
	}
}

int main(){
	fin >> m >> n;
		for(int i = 1; i <= m; ++i){
			fin >> a[i];
		}	
		for(int j = 1; j <= n; ++j){
			fin >> b[j];
		}
		for(int i = 1; i <= m; ++i){
			for(int j = 1; j <= n; ++j){
				if(a[i] == b[j]){
					cmlsc[i][j] = cmlsc[i-1][j-1]+1;
				}else{
					cmlsc[i][j] = max( cmlsc[i-1][j], cmlsc[i][j-1]);
				} 
			}
		}
		fout << cmlsc[m][n] << '\n';
		drum(m, n);		

}