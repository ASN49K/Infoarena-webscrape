#include <fstream>
#include <iostream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int T, A, B;

int gcd(int A, int B)
{
    if (!B) return A;
    if (A > B) return gcd(A-B, B);
    return gcd(A, B-A);
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
