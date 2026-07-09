#include <fstream>
 
using namespace std;
 
long gcd(long a, long b)
{
    if( a%b == 0 ) return b;
    else return gcd(b, a%b);
}
 
int main()
{
    ifstream inFile("euclid2.in");
    ofstream outFile("euclid2.out");
 
    int T, a, b;
    inFile >> T;
 
    while( T-- ){
        inFile >> a >> b;
        outFile << gcd(a, b) << "\n";
    }
