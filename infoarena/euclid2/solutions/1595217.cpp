#include<iostream>   
#include<fstream>
using namespace std;

int cmmdc(int a, int b){
	int aux;
	while (b){
		aux = b;
		b = a%b;
		a = aux;
	}
	return a;
}

int main(){
	ofstream output;
	ifstream input;
	input.open("euclid2.in");
	output.open("euclid2.out");
	int n;
	int a, b;
	input >> n;
	while (n>0){
		--n;
		input >> a;
		input >> b;
		output << cmmdc(a, b) << "\n";
	}

	input.close();
	output.close();

	return 0;

}