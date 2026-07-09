#include <iostream>
#include <fstream>
using namespace std;

long long int euclidAlg(long long int a, long long int b) {

	long long int r;
	while ((r = a%b))
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
	long long int i;

	for (i = 0; i < n; i++)
	{
		f >> a >> b;
		
		g << euclidAlg(a, b) << endl;
	}
		


}
