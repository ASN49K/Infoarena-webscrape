#include<fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n,a,b,i;

int euc(int a,int b)
{
	if(b==0) return a;
	else
		return euc(b,a%b);
}
int main()
{
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>a>>b;
		fout<<euc(a,b)<<"\n";
	}
}
