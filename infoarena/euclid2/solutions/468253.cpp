#include <fstream>

using namespace std;

long cmmdc(long a,long b)
{
	if(a%b==0)
		return b;
	else
		if(b%a==0)
			return a;
	else
		if(a>b)
			return cmmdc(a%b,b);
		else
			return cmmdc(a,b%a);
}

int main()
{
	long T,a,b,i;
	fstream fin,fout;
	fin.open("euclid2.in",ios::in);
	fout.open("euclid2.out",ios::out);

	fin>>T;
	for(i=0;i<T;i++)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b)<<'\n';
	}

	return 0;
}
