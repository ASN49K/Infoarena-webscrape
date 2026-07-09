//#include <iostream>
#include <fstream>

using namespace std;

int cmmdc (int a, int b)
{
	if (!a) 
		return b;
	if (!b)
		return a;
	return cmmdc (b, a%b);
}

int main()
{
	ifstream ifs ("euclid2.in");
	ofstream ofs ("euclid2.out");
	int n, a, b;
	ifs>>n;
	for (int i=0; i<n; i++)
	{
		ifs>>a>>b;
		ofs<<cmmdc(a,b)<<endl;
	}
}