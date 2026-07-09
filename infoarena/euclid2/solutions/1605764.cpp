#include <fstream>
using namespace std;
ifstream fin("cmmdc.in");
ofstream fout("cmmdc.out");
int main()
{
	int a,b;
	fin>>a;
	fin>>b;
	while(a!=b)
	{
		if(a>b)
			a=a-b;
		else
			b=b-a;
	}
	if(b!=1)
		fout<<b;
	else
		fout<<0;
	return 0;
}
