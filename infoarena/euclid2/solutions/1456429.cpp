#include <fstream>
using namespace std;

int euclid(int, int);

int main(int argc, char **argv)
{
	int n, a, b;
	ifstream indata("euclid2.in");
	indata >> n;
	
	ofstream outdata("euclid2.out");
	for (int i = 0; i < n; i++) {
		indata >> a >> b;
		outdata << euclid(a, b) << endl;
	}
	
	indata.close();
	outdata.close();
	return 0;
}

int euclid(int a, int b) {
	int r;
	
	do {
		r = a % b;
		a = b;
		b = r;
	} while(r != 0);

	return a;
}