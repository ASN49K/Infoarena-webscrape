#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int calcu (int a, int b)
{
	if(b==0) return a;
	else return calcu(b,a%b);
}

int main()
{
	int T,a,b;
	f>>T;
	while(T--)
	{
		f>>a>>b;
		g<<calcu(a,b)<<'\n';
	}
}