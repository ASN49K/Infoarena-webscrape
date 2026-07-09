#include <fstream>
using namespace std;
int main(void)
{
	ifstream m("euclid2.in");
	ofstream n("euclid2.out");
	int t,a,b,r,i;
	m>>t;
	for(i=1;i<=t;i++)
	{
		m>>a;
		m>>b;
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		n<<a<<"\n";
	}
	return 0;
}
