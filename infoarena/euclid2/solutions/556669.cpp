#include <iostream>
#include <fstream>

using namespace std;

const char iname[] = "euclid2.in";
const char oname[] = "euclid2.out";

ifstream fin(iname);
ofstream fout(oname);

long long t, a, b, i;

long long cmmdc(long long a, long long b)
{
	if(!b)
		return a;
	else
		return cmmdc(b, a % b);
}


int main()
{	
	fin >> t;
	for(i = 1; i <= t; i ++)
	{
		fin >> a >> b;
		fout << cmmdc(a, b) << "\n";
	}
	return 0;
}