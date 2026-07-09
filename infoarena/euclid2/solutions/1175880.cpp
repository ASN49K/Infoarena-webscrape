#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
	int c;
	while (b) {
		c = a;
		a = b;
		b = c % b;
	}
	return a;
}


int main()
{
	ifstream input;
	ofstream output;
	input.open("euclid2.in");
	output.open("euclid2.out");
	int T, a, b;
	
	input >> T;
	for (int i = 0; i < T; i++) {
		input >> a >> b;
		output << cmmdc(a, b) << endl;
	}
	
	input.close();
	output.close();

	return 0;
}