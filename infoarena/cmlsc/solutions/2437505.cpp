#include <iostream>
#include <fstream>
#include <algorithm>
#include <assert.h>
using namespace std;
int main(){
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int a[2000], b[2000], c[2000][2000], m, n, v[2000], k = 0,i, j;
	fin >> m >> n;
	for (i = 1; i <= m; i++){
		fin >> a[i];
	}
	for (j = 1; j <= n; j++){
		fin >> b[j];	
	}

	for (int i=1;i<=m;i++)
    {
        c[i][0]=0;
    }
	
    for (int i=1;i<=n;i++)
    {
        c[0][i]=0;
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
		 k++;
         v[k] = a[i];
         i--;
         j--;   
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