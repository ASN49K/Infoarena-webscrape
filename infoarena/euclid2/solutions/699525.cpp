#include<fstream>
using namespace std;
int main()
{
	int n,i,r,x,y;
	ifstream fin("euclid2.in");
	ofstream fout("euclid2.out");
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>x>>y;
		while(y!=0)
		{
			r=x%y;
			x=y;
			y=r;
		}
		fout<<x<<"\n";
	}
	fin.close();
	fout.close();
	return 0;
}
