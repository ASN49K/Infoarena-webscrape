#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,x,y,i;
int euclid(int a,int b)
{
	int r=1;
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
    fin>>n;
    for(i=1;i<=n;i++)
    {
    	fin>>x>>y;
    	if(x>y)
    	fout<<euclid(x,y)<<"\n";
    	else
    	fout<<euclid(y,x)<<"\n";
    }
    return 0;
}
