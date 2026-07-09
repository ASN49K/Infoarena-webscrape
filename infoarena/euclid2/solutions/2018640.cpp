#include<iostream>
#include<fstream>

//InfoArena
//Euclid

using namespace std;

int cmmdc(int a, int b) {
	if (a < b) {
		int aux = a;
		a = b;
		b = aux;
	}	
	while (a % b != 0) {
		int reminder = a % b;
		a = b;
		b = reminder;
	}
	return b;
}

int main() {
	ifstream f;
	ofstream g;
	f.open("euclid2.in");
	g.open("euclid2.out");
	int n, a, b;
	f >> n;
	for (int i = 0; i < n; i++) {

		f >> a >> b;
		g << cmmdc(a, b) << endl;

	}

	f.close();
	g.close();
	return 0;
}

