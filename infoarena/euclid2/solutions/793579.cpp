#include <fstream>
using namespace std;

#define IN_FILE		"euclid2.in"
#define OUT_FILE	"euclid2.out"

// Calculeaza cmmdc dintre a si b
int cmmdc(int a, int b) 
{
	int rest = a % b;
	while (rest != 0) 
	{
		a = b;
		b = rest;
		rest = a % b;
	}

	return b;
}


int main() 
{
	ifstream ifs(IN_FILE);
	ofstream ofs(OUT_FILE);

	int T = 0; 
	ifs >> T;

	for (int i = 0; i < T; ++i) 
	{
		int a = 0;
		int b = 0;
		ifs >> a >> b;
		ofs << cmmdc(a, b) << "\n";
	}

	ifs.close();
	ofs.close();
	return 0;
}