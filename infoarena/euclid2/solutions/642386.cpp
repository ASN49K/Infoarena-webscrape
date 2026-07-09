using namespace std;
#include<fstream>
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b,r;
int main()
{
	fin>>n;
	while(n--)
	{
		fin>>a>>b;
		r=1;
		while(r)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<"\n";
	}
	return 0;
}
