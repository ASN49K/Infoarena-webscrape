#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long  a,b,i;
long cmmdc(long a,long b)
{
	if(b)
		return cmmdc(b , a%b);
	else
		return a;
}
int main()
{
	int T;
	fin >> T;
	for( i=1; i <= T; i++)
	{
		fin>> a >> b;
		fout << cmmdc (a , b) << '\n' ;
	}
	fin.close();
	fout.close();
	return 0;
}
