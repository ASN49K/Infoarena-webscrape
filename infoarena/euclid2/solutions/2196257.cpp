#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;

long long cmmdc(long long a, long long b)
{
	if(b==0)
	    return a;
	return cmmdc(b,a%b);
}

int main()
{
    
    fin >> T;
    
    for(;T;T--)
    {
    	long long a,b;
    	fin >> a >> b;
    	fout << cmmdc(a,b) << endl;
	}
    
    return 0;
    
}
