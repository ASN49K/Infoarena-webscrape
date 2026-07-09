#include<fstream>
using namespace std;
int cmmdc(int a,int b)
{
	if(a%b==0) return b;
	else return cmmdc(b,a%b);
}
int main ()
{
	int t;
	ifstream fin("euclid2.in");
	fin>>t;
	ofstream fout("euclid2.out");
	int i,a,b;
	for(i=1;i<=t;i++)
	{
		fin>>a>>b;
		fout<<cmmdc(a,b)<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}