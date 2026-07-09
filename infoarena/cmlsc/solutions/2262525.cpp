#include <iostream>
#include <fstream>
using namespace std;
int main(){
	int m, n, i,l,j,a;
	int v1[1025];
	int v2[1025];
	int array[1025];
	ifstream file("cmlsc.in");	
	file >> n;
	file >> m;
	for (i = 0; i < n; i++) {
		file >> v1[i];
	}
	for (j = 0; j < m; j++) {
		file >> v2[j];
	}
	int cont = 0;
	l = -1;
	for (int i = 0; i < n; i++)
		for (int j=l+1;j<m;j++)
			if (v1[i] == v2[j])
			{
				cont++;
				array[cont - 1] = v1[i];
				l = j;
				break;
			}
	ofstream outfile("cmlsc.out");
	outfile << cont << "\n";
	for (int i = 0; i < cont; i++)
		outfile<< array[i] << " ";	
	system("pause");
	return(0);
	
}