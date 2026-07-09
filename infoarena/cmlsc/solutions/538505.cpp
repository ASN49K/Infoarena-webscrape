#include <fstream.h>
#include <iostream.h>

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], n, m, L[1025][1025], max;

int maximum(int, int);

int cmlsc(int S[], int T[]) {
	int i_max, j_max;
	for(int i=n; i>=1; i--)
		for(int j=m; j>=1; j--) {
			if(S[i] == T[j]) 
				L[i][j] = L[i+1][j+1] + 1;
			else
				L[i][j]  = maximum(L[i+1][j], L[i][j+1]);
			
			if(L[i][j] > max) {
				max = L[i][j];
				i_max = i;
				j_max = j;
			}
		}
	/*for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++)
			cout<<L[i][j]<<" ";
		cout<<'\n';
	}
	cout<<i_max<<" "<<j_max;
	*/
	fout<<max<<'\n';
	while (max) {
		if(S[i_max] == T[j_max] ) {
			fout<<S[i_max]<<" ";
			i_max++;
			j_max++;
			max--;
		}
		else if(L[i_max+1][j_max] > L[i_max][j_max+1])
			i_max++;
		else j_max++;
	}		
	// numarul de subsiruri comune este max
	//return max;
}

int main() {
	fin>>n>>m;
	for(int i=1; i<=n; i++)
		fin>>a[i];
	for(int i=1; i<=m; i++)
		fin>>b[i];
	
	cmlsc(a,b);
}

int maximum(int x, int y) {
	return x>y ? x : y;
}