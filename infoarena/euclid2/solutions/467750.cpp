#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
	int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int main()
{
	int i,t,a,b;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b)<<endl;
	}
	fin.close();
	fout.close();
}
