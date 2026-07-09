#include <fstream>
using namespace std;

int main()
{
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	
	int n,i,a,b,aux;
	fin>>n;

	for (i=1;i<=n;i++)
	{
		int a,b;
		fin>>a>>b;

		while (b!=0)
		{
			aux=b;
			b=a%b;
			a=aux;
		}

		fout<<a<<'\n';
	}
	
	fout.close();
	return 0;
	
}

