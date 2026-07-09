#include<fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, a, b;
int cmmdc(int a, int b)
{
	if(b == 0)
		return a;
	else
		return cmmdc(b, a%b);
}
int main()
{
	fin>>n;
	int i, aux;
	for(i=1;i<=n;i++)
	{
		fin>>a>>b;
		//fout<<cmmdc(a,b)<<'\n';
		while(b!=0)
		{
			aux = a;
			a = b;
			b = aux%b;
		}
		fout<<a<<'\n';
	}
	return 0;
}