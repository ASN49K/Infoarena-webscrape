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
	cin >> T;
	for (int A, B; T; --T)
	{
		cin >> A >> B;
		cout << Euclid(A, B) << '\n';
	}
}