#include <fstream>

using namespace std;

int gcd(int a, int b) {
    if (b > 0)
        return gcd(b, a % b);
    else
        return a;
}

int main()
{
	int nrRows, first, second;
	ifstream inputFile("euclid2.in");
	ofstream outputFile("euclid2.out");
	inputFile >> nrRows;
	while( nrRows-- ) {
		inputFile >> first >> second;
		outputFile << gcd(first,second) << "\n";
	}
	inputFile.close();
	outputFile.close(); 
	return 0;
};
