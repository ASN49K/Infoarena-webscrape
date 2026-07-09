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
	vector<int> a(n+1), b(m+1),sir;
	vector<vector<int>> c(n+1,vector<int>(m+1));
	for (i = 1; i <=n; i++){
		file >> a[i];
	}
	for (j = 1; j <=m; j++){
		file >> b[j];
	}
	for (i = 1; i <=n; i++)
		for (j = 1; j <=m; j++)
			if (a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else c[i][j] = max(c[i][j - 1], c[i - 1][j]);

	file.close();
	file.open("cmlsc.out", ios::out);
	file << c[n][m] << endl;
	for (i = n, j = m; i && j;){
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