#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

class Euclid {
	int first_number;
	int second_number;
public:
	Euclid(int a, int b)
	{
		first_number = a;
		second_number = b;
		int rest = 0;
		while (second_number != 0)
		{
			rest = first_number % second_number;
			first_number = second_number;
			second_number = rest;
		}
		g << first_number << "\n";
	}
};

int main()
{
	int queries, a, b;
	f >> queries;
	while (queries--)
	{
		f >> a >> b;
		Euclid(a, b);
	}
	return 0;
}