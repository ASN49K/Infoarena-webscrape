#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int gcd(int dividend, int divisor) {
	if (!divisor)
		 return dividend;
	else
		gcd(divisor, (dividend%divisor));
}
int main()
{
	int t;
	int a, b;
	f >> t;
	for(int i=0;i<t;++i){
		f >> a;
		f >> b;
		g<<gcd(a, b)<<'\n';
	}
	return 0;
}