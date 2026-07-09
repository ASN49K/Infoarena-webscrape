#include <iostream>
#include <fstream>
using namespace std;

int euclidAlg(long long int a, long long int b) {

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

	ifstream f("euclid2.in");
	ofstream g("euclid2.out");

	long long int n;
	f >> n;

	long long int a, b;
	for (int i = 0; i < n; i++)
	{
		f >> a >> b;
		
		g << euclidAlg(a, b) << endl;

	}
		


}
