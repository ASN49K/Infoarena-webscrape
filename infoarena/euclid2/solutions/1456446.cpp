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
		outdata << euclid(a, b) << "\n";
	}
	
	indata.close();
	outdata.close();
	return 0;
}

int euclid(int a, int b) {
	if (b == 0) {
		return a;
	}
	
	return euclid(b, a % b);
}