#include <fstream>

std::ifstream Input("data_in.txt");
std::ofstream Output("data_out.txt");

unsigned long Euclid(unsigned long a, unsigned long b)
{
	if (a > b)
	{
		if (a%b == 0)
			return b;
		return Euclid(a%b, b);
	}
	else
	{
		if (b%a == 0)
			return a;
		return Euclid(a, b%a);
	}
}


int main(void)
{
	unsigned int n;
	Input >> n;
	unsigned long a, b;
	while (Input >> a)
	{
		Input >> b;
		Output << Euclid(a, b) << "\n";
	}

	return 0;
}