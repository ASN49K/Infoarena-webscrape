#include<fstream>
using namespace std;

int main()
{
	ifstream in_file("euclid2.in");
	ofstream out_file("euclid2.out");
	unsigned number1, number2, pair_number, remainder;
	for (in_file >> pair_number; pair_number; --pair_number)
	{
		in_file >> number1 >> number2;
		while (number2)
		{
			remainder = number1 % number2;
			number1 = number2;
			number2 = remainder;
		}
		out_file << number1 << '\n';
	}
	return 0;
}