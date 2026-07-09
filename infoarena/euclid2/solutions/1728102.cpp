#include <iostream>
#include <fstream>
using namespace std;

long long int euclidAlg(long long int a, long long int b) {

	if (a == 0 || b == 0)
		return 0;

	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;

	long long int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}

	return b;

}
int main() {

	ifstream f("in.in");
	ofstream g("out.out");

	long long int n;
	f >> n;

	long long int a, b;
	for (long long int i = 0; i < n; i++)
	{
		f >> a >> b;
		
		if (a == 0 || b == 0)
			g << 0 << endl;
		else {
			if (a < 0)
				a = -a;
			if (b < 0)
				b = -b;

			long long int r;
			while (r = a%b)
			{
				a = b;
				b = r;
			}
			g << b << endl;
		}
	}
		


}
