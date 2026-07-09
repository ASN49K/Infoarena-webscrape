#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define MAX(a,b) (((a)>(b))?(a):(b))

using namespace std;

int mat [1025][1025], dir[1025][1025],m, n;


vector <int> vec, vec2;

int find (int i, int j) {

	//cout<<i<<" "<<j<<endl;
	
	if (mat[i+1][j+1] >=0 )
		return mat[i+1][j+1];

	if (i == -1 || j == -1)
		mat[i+1][j+1] = 0;
		
	else if (vec[i] == vec2[j]) {
	
		mat[i+1][j+1] = 1 + find (i-1, j-1);
		dir[i+1][j+1] = 1;
		
	}
	else {
		mat[i+1][j+1] = MAX (find(i-1,j), find(i, j-1));
		
		if (mat[i][j+1] > mat[i+1][j])
			dir[i+1][j+1] = 0;
		else
			dir[i+1][j+1] = 2;
	}
		
	return mat[i+1][j+1];
	
}


int main() {

int i, j, k;

int dmin[101][101];

FILE *fin, *fout;

fin = fopen ("cmlsc.in", "r");

freopen("cmlsc.out", "w", stdout);


fscanf (fin, "%d %d", &n, &m);

vec.resize(n);
vec2.resize(m);

for (i = 0; i <= n; i++) 
	for (j = 0; j <= m; j++) 
		mat[i][j] = -1;
		

for (i = 0; i < n; i++) {
	fscanf (fin, "%d", &vec[i]);
}

for (i = 0; i < m; i++) {
	fscanf (fin, "%d", &vec2[i]);
}

//find (n-1, m-1);

cout<<find (n-1, m-1)<<endl;

/*for (i = 0; i <= n; i++) {
	for (j = 0; j <= m; j++) {
		cout<<mat[i][j]<<" ";
	}
	cout<<endl;
}

cout<<endl;

for (i = 0; i <= n; i++) {
	for (j = 0; j <= m; j++) {
		cout<<dir[i][j]<<" ";
	}
	cout<<endl;
}*/

vector <int> vec3;
vec3.resize(mat[n][m]);

int poz = mat[n][m];
int c;
i = n;
j = m;

while (poz>0) {
	c = vec[i-1];
	if (dir[i][j] == 0) {
		i--;
	}
	else if (dir[i][j] == 1) {
		i--;
		j--;
	}
	else
		j--;
		
	if (poz > mat[i][j]) {
		poz--;
		vec3[poz] = c;
	}
} 

for (j = 0; j < vec3.size(); j++) {
		cout<<vec3[j]<<" ";
	}
	cout<<endl;

return 0;

}



