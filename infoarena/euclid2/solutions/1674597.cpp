#include <fstream>
#include <iostream>
 
using namespace std;
 
int gcd(int x, int y)
{
    if( y == 0) return x;
	gcd(y, x % y);
}
 
int main()
{
    ifstream fin("euclid2.in");
    ofstream fout("euclid2.out");
     
    int n, a, b;
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        fin >> a >> b;
        fout << gcd(a,b) << "\n";
    }
     
    return 0;
}
