#include<fstream>
using namespace std;

int main()
{
	fstream fin("euclid2.in",ios::in);
	fstream fout("euclid2.out",ios::out);
	
	int t;
	fin>>t;
	
	int a,b,r;
	for(register int i=1;i<=t;++i)
	{
		fin>>a>>b;
		while(b!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<endl;
	}
	fin.close();
	fout.close();

}