#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a, int b)
    {
        if (!b) return a;
        return gcd(b, a % b);
    }

int main()
{
	long long a,b,r,x;
    fin>>x;
    for(int i=1;i<=x;i++)
    {
        fin>>a>>b;
        fout<<gcd(a,b)<<endl;
    }
	return 0;
}

