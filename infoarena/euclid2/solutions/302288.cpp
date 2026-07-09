#include<fstream>
using namespace std;

int cmmdc(int a, int b)
{
	if (!b) return a;
	return cmmdc(a, a%b);
}

int main()
{
	int t, a, b;
	ifstream in ("euclid2.in");
	ofstream out ("euclid2.out");
	in>>t;

	for (int i=0;i<t;i++) {
		in>>a>>b;
		out<<cmmdc(a,b);
	}

	return 0;
}