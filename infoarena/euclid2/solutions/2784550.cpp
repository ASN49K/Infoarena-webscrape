#include <fstream>
#include <iostream>
using namespace std;


int main(){
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	long long  perechi, a , b;
	cin >> perechi;
	for (int e = 0; e < perechi; e++){
		in >> a >> b;
		while(a !=b)
			a>b ? a-=b : b-=a;
		
		out << a;
	}}
