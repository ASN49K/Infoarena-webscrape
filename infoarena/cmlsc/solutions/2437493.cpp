#include <iostream>
#include <fstream>
#include <algorithm>
#include <assert.h>
using namespace std;
int main(){
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int a[1000], b[1000], c[1000][1000], m, n, v[1000], k = 0,i, j;
	fin >> m >> n;
	for (i = 1; i <= m; i++){
		fin >> a[i];

	}
	for (j = 1; j <= n; j++){
		fin >> b[j];
		
	}
	fin.close();

	for (i = 1; i <= m; i++){
		for (j = 1; j <= n; j++){
			if(a[i] == b[j]){
				c[i][j] = c[i-1][j-1] + 1;
			} else {
				c[i][j] = std::max(c[i][j-1], c[i-1][j]);
			}
		}
	}

 i = m;
 j = n;
while(i > 0 && j > 0){
	if(a[i] == b[j]){
         v[k+1] = a[i];
         i--;
         j--;
         k++;
	} else {
		if(c[i][j-1] < c[i-1][j]){
		i--;
	}else{
		j--;
	}
	}
    
}
 
 fout << k << '\n';
 for (i = k; i >= 1; i--){
 	fout << v[i] <<" ";
 }
 fout.close();
 return 0;
}