#include <fstream>
#include <iostream>
using namespace std;

int divz(int x, int y) {
	int a = x;
	if (y < x) {
		a = y;
	}

	while (a > 1) {
		if (x % a == 0 && y % a == 0) 
			return a;
		else
			a--;
	}
	return a;
}

int main(int argc, char const *argv[])
{
	ifstream inFile;
	inFile.open("euclid2.in");

	ofstream outf("euclid2.out");

	int nums, x, y;
	inFile >> nums;

	for (int i = 0; i < nums; ++i) {
		inFile >> x >> y;
		outf << divz(x, y) << "\n";
	}

	outf.close();
	inFile.close();
	return 0;
}