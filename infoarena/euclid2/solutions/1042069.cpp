#include <iostream>
#include <fstream>
using namespace std;

int T, A, B;

int GCD(int a, int b)
{
	if(b == 0) return a;
	return GCD(b, a % b);
}

int main(int argc, char ** argv)
{

	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	f >> T;

	for(T; T; T--) {
		f >> A >> B;
		g << GCD(A, B) << endl;
	}
	return 0;
}
