#include<fstream>
using namespace std;

int n;

int euclid(int x, int y)
{
 int rest = x % y;

 while (rest != 0)
	{
	 x = y;
	 y = rest;
	 rest = x % y;
	}
 return y;
}

void read_solve()
{
 int i,a,b;
 ifstream fin("euclid2.in");
 ofstream fout("euclid2.out");
 fin>>n;
 for (i=1; i<=n; ++i)
	{
	 fin>>a>>b;
	 fout<<euclid(a,b)<<'\n';
	}
 fin.close();
 fout.close();
}

int main()
{
 read_solve();
 return 0;
}
