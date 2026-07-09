#include <fstream>

using namespace std;

int Euclid(int firstNumber, int secondNumber) {
	if (firstNumber == secondNumber)
		return firstNumber;
	if (firstNumber > secondNumber)
		return Euclid(firstNumber - secondNumber, secondNumber);
	return Euclid(firstNumber, secondNumber - firstNumber);
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

