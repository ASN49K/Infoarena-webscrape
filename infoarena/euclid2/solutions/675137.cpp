#include <fstream>
using namespace std;
int main (void)
{
	ifstream in("euclid2.in");
	ofstream out("euclid2.out");
	int i,n;
	long long a,b,r;
	in>>n;
	for (i=1;i<=n;i++)
	{
		in>>a>>b;
		r=a%b;
		while (r!=0)
		{
			a=b;
			b=r;
			r=a%b;
		}
		out<<b<<"\n";
	}
	in.close();
	out.close();
	return 0;
}