#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int gcd(int a, int b) {
	int c;
	while(b != 0)	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}
int main ()	{

	int T, a, b;
	fin >> T;
	for(int i = 1; i <= T; i++) {
			fin >> a >> b;
			fout << gcd(a, b) << "\n";
	}
	return 0;
}
