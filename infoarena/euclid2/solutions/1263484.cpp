#include<iostream>
#include<fstream>

using namespace std;

int plagiat(int a, int b){
	if (!b){ return a; }
	return plagiat(b, a%b);
}

int main(){
	int perechi,a,b;
	ifstream input("euclid2.in");
	ofstream output("euclid2.out");
	input >> perechi;
	for (int i = 1; i <= perechi; i++){
		input >> a >> b;
		output << plagiat(a,b) << "\n";
	}
	input.close();
	output.close();
	return 0;
}
