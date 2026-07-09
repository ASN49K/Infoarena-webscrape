#include <fstream>

using namespace std;

long CMMDC(long a, long b);

int main()
{
	long numA, numB;
	int T;

	ifstream inFILE("euclid2.in");
	ofstream outFILE("euclid2.out");

	inFILE >> T;

	for (int i = 1; i <= T; i++)
	{
		inFILE >> numA >> numB;
		outFILE << CMMDC(numA,numB) << "\n";
	}

	// system("pause");  <- Visual C++ 2010
	return 0;
}

long CMMDC(long a, long b)
{
	if (b == 0)
		return a;
	else
		return CMMDC(b,a%b);
}