#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
	int n, m,i, j;
	fstream file;
	file.open("cmlsc.in", ios::in);
	file >> n >> m;
	vector<int> a(n), b(m),sir;
	vector<vector<int>> c(n,vector<int>(m));
	for (i = 0; i < n; i++){
		c[i][0] = (a[i] == b[0] ? 1 :0);
		file >> a[i];
	}
	for (j = 0; j < m; j++){
		c[0][j] = (a[0] == b[j] ? 1 : 0);
		file >> b[j];
	}
	for (i = 1; i < n; i++)
		for (j = 1; j < m; j++)
			if (a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = max(c[i][j - 1], c[i - 1][j]);

	file.close();
	file.open("cmlsc.out", ios::out);
	
	i = n - 1; j = m - 1;
	file << c[i][j] << endl;
	while (i){
		if (a[i] == b[j]){
			sir.push_back(a[i]); i--; j--;
		}
		else{ 
			if (c[i - 1][j] < c[i][j - 1])
			--j;
			else
			--i;
		}
	}
	for (i = sir.size()-1; i>=0; i--) file << sir[i] << " ";
	file.close();
	return 0;
}