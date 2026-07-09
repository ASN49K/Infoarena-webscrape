#include <fstream>
using namespace std;
ifstream fin("nim.in");
ofstream fout("nim.out");
int v[10001],t,n,xo,i,i2;
int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
    	fin>>n;
    	for(i2=1;i2<=n;i2++)
			fin>>v[i2];
		xo=v[1];
		for(i2=2;i2<=n;i2++)
		xo=xo^v[i2];
		if(xo==0)
		fout<<"NU"<<"\n";
		else
		fout<<"DA"<<"\n";
    }
    return 0;
}
