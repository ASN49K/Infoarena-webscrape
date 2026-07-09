#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(long int a, long int b)
{
	while(a > 0)
	{
		long int t = a;

		a = b%a;
		b = t;
	}	

	return b;
}	

int main()
{
	int n;
	long int a, b;
	
	in>>n;
	
	for(int i=1; i<=n; i++)
	{
		in>>a>>b;

		out<<euclid(a, b)<<'\n';		
	}	
	
	out.close();
	return 0;
}	