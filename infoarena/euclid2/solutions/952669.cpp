#include<fstream>
using namespace std;
 
int a,b,r;
 
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
	fin>>T;
	while(T)
	{
		fin>>a>>b;
		r=a%b;
		while(r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		if(b==1)
			fout<<0<<'\n';
		else fout<<b<<'\n';
		--T;
	}
    return 0;
}