#include<fstream>
using namespace std;
int main()
{
	int a,b,r,i,n;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>n;
	for( i=1; i<=n; i++)
	{	
		fin>>a; fin>>b;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}