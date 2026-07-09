#include <fstream>
using namespace std;

int n,r,a,b;

int main()
{
ifstream in("euclid.in");
ofstream out("euclid.out");

in>>n;
for(int i1=0; i1<n; i1++)
	{
	in>>a>>b;
	r=a%b;
	while(r)
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