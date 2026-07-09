#include<fstream>
using namespace std;
int n,a,b;
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	for(int i=1;i<=n;i++)
	{
		f>>a>>b;
		while(a!=b)
		{
			if(a>b)
				a-=b;
			else
				b-=a;
		}
		g<<a<<'\n';
	}
}