#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int n, A, B;

int calc(int a, int b)
{
	if(!b)
		return a;
	return calc(b, a % b);
}


int main()
{
    fin>>n;
    for(int i=1; i<=n; ++i)
    {
    	fin>>A>>B;
    	fout<<calc(A, B)<<endl;
	}
	return 0;
}
