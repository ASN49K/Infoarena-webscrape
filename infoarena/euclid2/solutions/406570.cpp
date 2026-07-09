#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int euclid ( int a, int b ) {
	int t;
	while ( b!= 0 ) 
	{
		t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int main() {
	ifstream input;
	ofstream output;
	string line;
	int nb;
	int a,b,i;
	
	input.open("euclid2.in");
	output.open("euclid2.out");
	if ( !input.is_open() || !output.is_open() ) {
		cout << "Eroare";
		return 1;
	}
	
	getline ( input, line );
	stringstream ( line ) >> nb;
	for ( i=0; i<nb; i++ )
	{
		getline ( input, line );
		stringstream (line) >> a >> b;
		output << euclid(a,b) << endl;
	}
	
	input.close();
	output.close();
	return 0;

}
