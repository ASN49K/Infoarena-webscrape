#include<fstream>
#include<iostream>
using namespace std;

int a[100],b[100],x[100][100],n,m;

ofstream g("cmlsc.out");

void citire() {
	ifstream f("cmlsc.in");
	f>>m>>n;
	for (int i=0 ; i<m ; i++)
		f>>a[i];
	for (int i=0 ; i<n ; i++)
		f>>b[i];
	f.close();
}

/*void afis() {
	for (int i=0 ; i<m ; i++) cout<<a[i]<<" ";
	cout<<endl;
	for (int i=0 ; i<n ; i++) cout<<b[i]<<" ";
}*/
int max(int i, int j) {
	if (i<j) return j;
	else return i;
}

void calcul() {
	for (int i=0 ; i<m ; i++)
		for (int j=0 ; j<n ; j++)
			if (a[i]==b[j])
				x[i][j]=x[i-1][j-1]+1;
			else 
				x[i][j]=max(x[i-1][j], x[i][j-1]);
}

void scrie(int i, int j) {
	if (x[i][j]==0)
		return;
	if (a[i]==b[j]) {
		scrie(i-1, j-1);
		g<<a[i]<<" ";
		return;
	}
	if (x[i-1][j]>x[i][j-1])
		scrie(i-1, j);
	else
		scrie(i, j-1);
}

void main() {
	citire();
	calcul();
	//afis();
	scrie(n-1,m-1);
	g.close();
}
