#include <fstream>

using namespace std;

int Euclid(int firstNumber, int secondNumber) {
	if (! secondNumber)
		return firstNumber;
	return Euclid(secondNumber, firstNumber % secondNumber);
}

int main()
{
	int T, firstNumber, secondNumber;
	ifstream inputFile("euclid2.in");
	ofstream outputFile("euclid2.out");

	inputFile >> T;
	for (int i = 0; i < T; i++) {
		inputFile >> firstNumber;
		inputFile >> secondNumber;
		outputFile << Euclid(firstNumber, secondNumber) << "\n";
	}
    return 0;
}

