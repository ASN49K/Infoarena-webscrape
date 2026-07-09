#include <stdio.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

ifstream in("euclid.in");
ofstream out("euclid.out");

int euclid(int a, int b){
	while(b){
		int c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(){
	int n;
	in >> n;
	for(int i = 0; i<n; i++){
		int a, b;
		in >> a >> b;
		out << euclid(a, b) << "\n";
	}	
}

/*
	88 33
	88 / 33 = 2 rest 22
	33 / 2 = 16 rest 1
	2 / 16 = 0 rest 2

	24 / 12 = 2 rest 0
	12 / 2 = 6 rest 0
	2 / 6 = 0 rest 2
*/