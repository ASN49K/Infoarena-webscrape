#include <fstream>
using namespace std;
	
int T, A, B;
 
int gcd(int A, int B)
{
    if (!B) return A;
    if (A > B) return gcd(A-B, B);
    return gcd(A, B-A);
}

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
	in >> T;
	for(int i = 0; i < T; i++)
	{
		in >> A >> B;
		out << gcd(A, B) << endl;
	}

	in.close();
	out.close();
	return 0;
}