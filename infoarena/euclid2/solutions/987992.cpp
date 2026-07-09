#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int t;

int euclid(int a, int b)
{
	if(a % b == 0)
		return b;
	
	return euclid(b, a%b);
}	

int main()
{
	in>>t;
	
	for(int i=1; i<=t; i++)
	{
		int a, b;
		
		in>>a>>b;
		
		out<<euclid(a, b)<<'\n';
	}

	in.close();
	out.close();
	return 0;
}	