#include <iostream>
#include <fstream>

using namespace std;

int GCD(long long int a, long long int b)
{
	if (!b)
		return a;
	return GCD(b, a%b);
}

int main()
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");

	int n;
	long long int a, b;

	in >> n;
	for (int i = 0; i < n; i++)
	{
		in >> a >> b;
		out << GCD(a, b) << "\n";
	}

	return 0;
}