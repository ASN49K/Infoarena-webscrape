#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#include <iostream>
#include <fstream>
using namespace std;

int euclidAlg(int a, int b) {

	if (a == 0 || b == 0)
		return 0;

	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;

	int r;
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

	int n;
	f >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		f >> a >> b;
		
		g << euclidAlg(a, b) << endl;

	}
		


}
