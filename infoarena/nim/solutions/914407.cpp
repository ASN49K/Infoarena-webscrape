// Include
#include <fstream>
using namespace std;

// Variabile
ifstream in("nim.in");
ofstream out("nim.out");

int tests;
int num, xorSum;

// Main
int main()
{
	in >> tests;
	while(tests--)
	{
		in >> num;
		in >> xorSum;
		
		int readVal;
		while(--num)
		{
			in >> readVal;
			xorSum ^= readVal;
		}
		out << (xorSum? "DA" : "NU") << '\n';
	}
	
	in.close();
	out.close();
	return 0;
}
