#include <fstream>
using namespace std;

int a,b,c,t,i;
int main ()
{
	ifstream f ("euclid2.in");
	ofstream g ("euclid2.out");
	f >>t;
	for (i=1; i<=t; i++)
	{
		f >>a>>b;
		while (b)
		{
			c=b;
			b=a%b;
			a=c;
		}
		g <<a<<endl;
	}
	return 0;
}
