#include <fstream>
#include <iostream>
using namespace std;

int divz(int x, int y) {
	int rest = 1, q1 = x, q2 = y;
	if (y < x) {
		q2 = x;
		q1 = y;
	}

	while (rest > 0) {
		rest = q2 % q1;
		q2 = q1;
		q1 = rest;
		if (rest == 1)
			return rest;
	}

	return q2;
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