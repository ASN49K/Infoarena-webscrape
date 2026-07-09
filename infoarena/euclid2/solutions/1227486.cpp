#include<iostream>
#include<fstream>

using namespace std;

int gcd(int a, int b){
	if (!b){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}

int main(){
	int a, b, nrPairs;

	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	f >> nrPairs;

	while (nrPairs){
		f >> a >> b;
		g << gcd(a, b)<<"\n";
		nrPairs--;
	}

	return 0;
}