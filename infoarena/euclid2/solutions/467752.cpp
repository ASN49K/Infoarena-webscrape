#include<fstream>
using namespace std;
int cmmdc(int a, int b)
{
	if(b==0)
		return a;
	return cmmdc(b, a%b);
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
