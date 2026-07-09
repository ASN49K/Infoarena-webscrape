#include<fstream>
using namespace std;
ifstream gheo("euclid2.in");
ofstream ion("euclid2.out");
int n,a,b,r,i;
int main()
{
	gheo>>n;
	for(i=1;i<=n;i++)
	{
		gheo>>a>>b;
		r=0;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		ion<<a<<'\n';
	}
	ion.close();
	return 0;
}
