#include <iostream>
#include <fstream>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int i, j, n, m, p, maxim = -1, iMaxim, jMaxim, *a, *b, *cmlsc, **v;

	//Read input
	in>>n>>m;
	a = new int[n];
	b = new int[m];
	v = new int*[n];
	for (i = 0 ; i < n ; i ++) {
		in>>a[i];
		v[i] = new int[m];
	}
	
	for (j = 0 ; j < m ; j ++) 
		in>>b[j];

	//Fill the matrix
	v[0][0] = (a[0] == b[0]) ? 1 : 0;
	
	for (i = 1 ; i < n ; i ++) 
		if (a[i] == b[0]) v[i][0] = 1;
		else v[i][0] = v[i - 1][0];

	for (j = 1 ; j < m ; j ++) 
		if (a[0] == b[j]) v[0][j] = 1;
		else v[0][j] = v[0][j - 1];

	for (i = 1 ; i < n ; i ++) 
		for (j = 1 ; j < m ; j ++) {
			if (a[i] == b[j]) v[i][j] = v[i - 1][j - 1] + 1;
			else v[i][j] = max(v[i - 1][j], v[i][j - 1]);

			if (v[i][j] > maxim) {
				maxim = v[i][j];
				iMaxim = i;
				jMaxim = j;
			}
		}

	cmlsc = new int[maxim];
	i = iMaxim;
	j = jMaxim;
	p = maxim - 1;
	while (i >= 0 && j >= 0) {
		if (a[i] == b[j]) {
			cmlsc[p] = a[i];
			p--;
			i--;
			j--;
		}
		else {
			if (i == 0) j--;
			else if (j == 0) i--;
			else {
				if (v[i - 1][j] > v[i][j - 1]) i--;
				else j--;
			}
		}
	}

	out<<maxim<<"\n";
	for (i = 0 ; i < maxim ; i ++) 
		if (i < maxim - 1) out<<cmlsc[i]<<" ";
		else out<<cmlsc[i];


	return 0;
}