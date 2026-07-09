#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
		if(a<b)
			cmmdc(b, a);
		else
			if(a==b)
				return a;
			else
				return (cmmdc(a-b,b));
}
			


void citire_fisier(int a[],  int b[], int &T)
{
	ifstream fin("euclid2.in");
	fin>>T;
	for(int i=0; i<T; i++)
	{
		fin>>a[i];
		fin>>b[i];
	}
	fin.close();
}

int main()
{
	int T;
	int a[200], b[200], div[200];

	citire_fisier(a, b, T);

	ofstream fout("euclid2.out");
	for(int i=0; i<T; i++)
		fout<<cmmdc(a[i],b[i])<<"\n";

	

	return 0;
}