#include<fstream>
using namespace std;
int n,t;

int main()
{
	int i,j,x,sumaxor;
	ifstream fin("nim.in");
	ofstream fout("nim.out");
	fin>>t;
	for(i=1;i<=t;i++)
	{
		fin>>n;
		sumaxor=0;
		for(j=1;j<=n;j++)
		{
			fin>>x;
			sumaxor=sumaxor^x;
		}
		if(sumaxor)
			fout<<"DA\n";
		else
			fout<<"NU\n";
	}
	fin.close();
	fout.close();
	return 0;
}
