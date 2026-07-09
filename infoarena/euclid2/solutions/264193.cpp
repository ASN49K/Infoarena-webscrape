#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
	long i,n,a,b,r;
	f>>n;
	for(i=1;i<=n;i++) 
	{
		f>>a>>b;
		while(b) { r=a%b; a=b; b=r; }
		g<<a<<endl;
	}
f.close();
g.close();
}
