#include <fstream>
using namespace std;

ifstream is ("euclid2.in");
ofstream os ("euclid2.out");

int Euclid(int a, int b){
    if(!b) return a;
    return Euclid(b, a % b);
}

int main()
{
	int T;
	is >> T;
	for (int A, B; T; --T)
	{
		is >> A >> B;
		os << Euclid(A, B) << '\n';
	}
}