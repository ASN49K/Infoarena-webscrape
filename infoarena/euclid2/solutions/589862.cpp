#include <fstream>
using namespace std;

int n,m;
int a,b,r;

int main()
{
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int i1;

in>>n;

for(i1=0;i1<n;i1++)
	{
	in>>a>>b;
	r=a%b;
	while(r)
		{
		a = b;
		b = r;
		r = a%b;
		}
	out<<b<<'\n';
	}

in.close();
out.close();
return 0;
}