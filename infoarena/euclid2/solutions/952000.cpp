#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
	int a,b,n,aux=0,t=0;
	fin>>n;
	for(;n;n--)
	{
		fin>>a>>b;
		if(b>a)
		{
			aux=a;
			a=b;
			b=aux;
		}
		while(b)
		{
			t=b;
			b=a % b;
			a=t;
		}
		fout<<a<<"/n";
	}
	fin.close();
	fout.close();
}
