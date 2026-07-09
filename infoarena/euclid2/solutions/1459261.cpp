#include <iostream>
#include <fstream>
#define fin "euclid2.in"
#define fou "euclid2.out"
using namespace std;
ifstream t1(fin);
ofstream t2(fou);

int cmmdc(int a, int b)
{
	if(!b) return a;
	else cmmdc(b,a % b);
}

int main()
{
	int n, i,a,b;
	t1 >> n;
	for (i = 1; i <= n;i++)
	{
		t1 >> a>> b;
        t2 << cmmdc(a,b)<<'\n';
	}
	t1.close();
	t2.close();
	return 0;
}
