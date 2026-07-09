#include<fstream>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long gcd(long long a,long long b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
long long x,y;
int n;
int main()
{
	fin>>n;
	for(;n;n--)
	{
		fin>>x>>y;
		fout<<gcd(x,y)<<endl;
	}
	
	
	return 0;
}
