#include<fstream>
using namespace std;

long computeEuclid(long a, long b) {
	
	long c = 1;

	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return b;
}

int main() {

	ifstream inFile("euclid2.in");
	ofstream outFile("euclid2.out");

	int T;
	long a, b;

	inFile >> T;
	for (int i = 0; i < T; ++i) {
		inFile >> a >> b;
		outFile << computeEuclid(a, b) <<"\n";
	}
	inFile.close();
	outFile.close();
	return 0;
}