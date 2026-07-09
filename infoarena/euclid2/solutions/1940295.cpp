#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int prime(int x) {
	int t = 0;
	for (int i = 2; i <= x; i++)
		if (x%i == 0)
			t++;
	if (t == 1)
		return 1;
	else
		return 0;
}
void gdc(int long long dividend, int long long divisor) {
	if ((dividend) && (divisor)) {
		int quotient = dividend / divisor;
		int remainder = dividend - (divisor*quotient);
		gdc(divisor, remainder);
	}
	else g << dividend<<endl;
}
int main()
{
	int t;
	int long long a, b;
	f >> t;
	for (int i = 0; i < t; i++)
	{
		f >> a;
		f >> b;
		if (a > b)
			gdc(a, b);
		else
			gdc(b, a);
	}
	f.close();
	g.close();
	return 0;
}