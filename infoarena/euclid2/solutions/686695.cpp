#include<fstream>
using namespace std;
int main()
{
	int a,b,s=0;
	ifstream f("adunare.in");
	ofstream g("adunare.out");
	f>>a>>b;
	s=a+b;
	g<<s;
	return 0;
}