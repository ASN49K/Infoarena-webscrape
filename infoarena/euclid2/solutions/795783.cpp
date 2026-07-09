#include <fstream> 

using namespace std; 

ifstream fin("euclid2.in");
ofstream fout("euclid2.out");

int gcd(int a,int b) { return !b ? a : gcd(b,a%b);}

int main()
{
	int T, a, b;
	for(fin>>T;T;T--) { 
		fin>>a>>b;
		fout<<gcd(a,b)<<"\n";
	}
	return 0;
} 
 