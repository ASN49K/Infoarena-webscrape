#include<fstream>
using namespace std;
ifstream g("euclid2.in");
ofstream f("euclid2.out");
long n , a ,b;
int cmmdc(int a , int b)
{
	while(a!=b)
	{
		if(a>b) a-=b;
			else b-=a;
	}
return a;
}
int main ()
{
	g>>n;
	while(n)
	{
		g>>a;
		g>>b;
		f<<cmmdc(a,b)<<'\n';
		n--;
	}
	f.close();
	g.close();
return 0;
}