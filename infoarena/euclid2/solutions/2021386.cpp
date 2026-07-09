#include<fstream>
using namespace std;

int cmmdc(int a, int b)
{
	if (b == 0) return a;
	return cmmdc(b, a%b);
}

int main()
{
	int a, b;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int T;
	f >> T;
	for (;  T--;){
		f >> a >> b;
		g << cmmdc(a, b) << endl;
	}
	return 0;
}