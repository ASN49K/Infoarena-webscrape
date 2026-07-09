#include <fstream>

using namespace std;
int euclid(int a,int b)
{
	if(b==0)
	{
		return a;
	}
	else
	{
		return euclid (b,a%b);
	}
}
int main()
{
	ifstream f("euclid2.in");
	ofstream g("euclid2.out");
	long long int A,B,t;
	f>>t;
	for(t;t>0;t--)
	{
		f>>A;
		f>>B;
		g<<euclid(A,B)<<endl;
	}
}
	