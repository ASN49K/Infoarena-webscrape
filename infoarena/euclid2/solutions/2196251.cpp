#include <fstream>

using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T;

int cmmdc(int a, int b)
{
	if(b==0)
	    return a;
	else
	    return cmmdc(b,a%b);
}

int main()
{
    
    fin >> T;
    
    for(;T;T--)
    {
    	int a,b;
    	fin >> a >> b;
    	fout << cmmdc(a,b) << endl;
	}
    
    return 0;
    
}
