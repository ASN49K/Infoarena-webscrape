#include<fstream>
using namespace std;
int main()
{
	fstream f("euclid2.in");
	ofstream g("euclid2.out");
	int a,b;
	f>>a>>b;
	g<<a+b;
	return 0;
}
