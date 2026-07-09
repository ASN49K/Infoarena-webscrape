#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
unsigned t,a,b,i,r;
int main()
{
	fin>>t;
	
	for(i=1;i<=t;i++)
	{
		fin>>a>>b;
		
		r=0;
		
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<"\n";
	}
	return 0;
	
}
