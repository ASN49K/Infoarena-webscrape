#include <iostream>
#include <fstream>
using namespace std;

int a,b;
int GCD(int a, int b){
	if(!b)
		return a;
	return GCD(b, a % b);
}

int main(){
	ifstream infile;
	infile.open("euclid2.in");

	ofstream outfile;
	outfile.open("euclid2.out");

	int nr_perechi;

	infile >> nr_perechi;
	for(int i = 0; i < nr_perechi; i++){
		infile >> a >> b; //am citit a si b de pe ficare linie
		outfile << GCD(a,b) << endl;		
	}
	infile.close();
	outfile.close();
	return 0;
}