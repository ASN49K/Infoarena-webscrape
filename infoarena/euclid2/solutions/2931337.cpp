#include <fstream>

using namespace std;

int gcd(int a, int b) {
	int aux;
	while (b) {
		aux = a%b;
		a = b;
		b = aux;
	}
	return a;
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n, no1, no2;
	f >> n;
	for (int i = 1; i <= n; ++i) {
		f >> no1 >> no2;
		g<<gcd(no1, no2)<<"\n";
	}
	return 0;
}