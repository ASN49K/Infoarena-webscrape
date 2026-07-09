#include <fstream>

using namespace std;

int T,A,B;

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b, a % b);
}

int main()
{
	ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
    
    fin >> T;
    
    for(;T;T--)
    {
    	fin >> A >> B;
    	fout << gcd(A,B) << endl;
	}
    
    return 0;
    
}
