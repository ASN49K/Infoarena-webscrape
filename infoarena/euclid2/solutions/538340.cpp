#include<fstream>
using namespace std;
int main()
{
	int a,b,r,n;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>n;
	while(n)
	{	
		fin>>a; fin>>b;
		while(b)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fout<<a<<endl;
		n-=1;
	}
	fin.close();
	fout.close();
	return 0;
}