#include<fstream>
using namespace std;

int Euclid(int a,int b)
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
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	int n,i,k,a,b;
	fin>>n;
	for(i=0;i<n;i++)
	{
		fin>>a>>b;
		k=Euclid(a,b);
		fout<<k<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
