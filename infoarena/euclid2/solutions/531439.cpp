#include<fstream>
using namespace std;
int main()
{
	int n,a,b,r;
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	f>>n;
	while(n)
	{
		n--;
		cin>>a;
		cin>>b;
		r=a%b;
		while(r)
		{
			r=a%b;
			a=b;
			b=r;
		}
		g<<a<<endl;
	}
	f.close();
	g.close();
}
