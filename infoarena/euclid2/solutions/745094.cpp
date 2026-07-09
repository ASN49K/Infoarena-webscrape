//Include
#include <fstream>
using namespace std;

//Functii
inline int gcd(int a, int b)
{	return b? gcd(b, a%b) : a;	}

//Variabile
ifstream in("euclid2.in");
ofstream out("euclid2.out");

//Main
int main()
{
	int value1, value2;
	in >> value1;
	while(in >> value1 >> value2)
		out << gcd(value1, value2) << '\n';
	
	in.close();
	out.close();
	return 0;
}
