#include <fstream>
using namespace std;

ifstream fin("euclid.in");
ofstream fout("euclid.out");

unsigned long long a,b,n;

int euc(int a,int b)
{
	if(!b) return a;
	return euc(b,a%b);
}

int main()
{
	fin>>n;
	for(unsigned long long i=1;i<=n;i++)
		{
			fin>>a>>b;
			fout<<euc(a,b)<<'\n';
		}


}

