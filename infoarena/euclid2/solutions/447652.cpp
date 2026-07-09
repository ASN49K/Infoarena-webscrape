#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int a,b;

int cmmdc(int a,int b);

int main()
{
	f>>a>>b;
	g<<cmmdc(a,b);
	f.close();
	g.close();
	return 0;
}

int cmmdc(int a,int b)
{
	if (b)
		return (b,(a%b));
	return a;
}
			
	
