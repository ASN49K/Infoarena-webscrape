#include <fstream>
using namespace std;

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int T, A, B;

int calc(int a, int b)
{
	if(!b)
		return a;
	return calc(b, a % b);
}


int main()
{
    fin>>T;
    for(int i=1; i<=T; ++i)
    {
    	fin>>A>>B;
    	fout<<calc(A, B)<<"\n";
	}
	return 0;
}
