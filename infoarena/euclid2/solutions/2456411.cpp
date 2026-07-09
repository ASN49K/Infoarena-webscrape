#include <fstream>
#include <iostream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T, A, B;

int gcd(int A, int B)
{
    if (!B) return A;
    if (A > B) return gcd(B, A % B);
    else return gcd(B, A);
}

int main()
{
	for (in>>T; T; --T)
	{
		in>>A>>B;
		out<<gcd(A, B)<<'\n';
	}

	return 0;
}
