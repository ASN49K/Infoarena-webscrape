#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T,A,B;

int cmmdc(int a, int b)
{
	if(!b)
	    return a;
	return cmmdc(b,a%b);
}

int main()
{
    
    fin >> T;
    
    for(;T;T--)
    {
    	fin >> A >> B;
    	fout << cmmdc(A,B) << endl;
	}
    
    return 0;
    
}
