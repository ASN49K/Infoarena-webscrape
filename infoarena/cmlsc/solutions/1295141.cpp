#include<fstream>
using namespace std;
int n, m, i, j, k;
int v[1025], w[1025], a[1025][1025], sol[1025];
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int main(){
	fin>> n >> m;
	for(i = 1; i <= n; i++){
		fin>> v[i];
	}
	for(i = 1; i <= m; i++){
		fin>> w[i];
	}
	for(i = 1; i <= n; i++){
		for(j = 1; j <= m; j++){
			if(v[i] == w[j]){
				a[i][j] = a[i-1][j-1] + 1;
			}
			else{
				if(a[i-1][j] > a[i][j-1]){
					a[i][j] = a[i-1][j];
				}
				else{
					a[i][j] = a[i][j-1];
				}
			}
		}
	}
	fout<< a[n][m] <<"\n";
	i =  n;
	j = m;
	while(k != a[n][m]){
		if(v[i] == w[j]){
			sol[++k] = v[i];
			i--;
			j--;
		}
		else{
			if(a[i-1][j] > a[i][j-1]){
				i--;
			}
			else{
				j--;
			}
		}
	}
	for(i = k; i >= 1; i--){
		fout<< sol[i] <<" ";
	}
	return 0;
}