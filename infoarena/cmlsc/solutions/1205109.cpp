#include <iostream>
#include <fstream>

using namespace std;

int n, m, a[1026], b[1026], din[1026][1026];
ofstream g("cmlsc.out");

void reconstruct (int n, int m){ 
	if (n == 0 || m == 0) 
		return;
	if (a[n] == b[m]) {
		reconstruct (n-1, m-1);
		g << a[n];
		return;
	}
	if (din[n][m] == din[n-1][m])
		reconstruct (n-1, m);
	else 
		reconstruct (n, m-1);
}

void do_cmlsc() {
	for (int i = 1; i<= n ; i++) {
		for (int j = 1; j<= m ; j++) {
			if (a[i] == b[j]) {
				din[i][j] = max ( din[i][j], din[i-1][j-1] + 1 );
			}
			din[i][j] = max ( din[i][j], max ( din[i-1][j], din[i][j-1]));
		}
	}
}

void citire() {
	ifstream f("cmlsc.in");
	f>> n >> m ;
	for (int i = 1 ; i <= n; i++)
		f >> a[i] ;
	for (int i = 1 ; i <= m ; i++)
		f>> b[i];
	f.close();
}

int main() {
	citire();
	do_cmlsc();
	reconstruct (n, m);
	g.close();
}