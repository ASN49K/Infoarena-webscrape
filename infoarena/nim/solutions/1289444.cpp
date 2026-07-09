#include <iostream>
#include <fstream>


std::ifstream f("nim.in");
std::ofstream g("nim.out");


void do_test()
{
	int n;
	f >> n;

	int s = 0;
	for (int i = 1, x; i <= n; i++) {
		f >> x;
		s ^= x;
	}

	if (s) g << "DA\n";
	else g << "NU\n";
}


int main()
{
	int t; f >> t;
	for (int i = 1; i <= t; i++) {
		do_test();
	}

	return 0;
}