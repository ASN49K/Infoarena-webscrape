#include <fstream>

using namespace std;

long diviz(long a,long b)
{
	int r;
	r=a%b;
	while(r>0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

void program()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	int n,i;
	long a,b;
	i=1;
	f>>n;
	while(i<=n)
	{
		f>>a>>b;
		g<<diviz(a,b)<<"\n";
		i++;
	}
}

int main()
{
	program();
	return 0;
}

