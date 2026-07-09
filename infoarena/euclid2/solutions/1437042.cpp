#include <iostream>
#include <fstream>

using namespace std;


int gcd(long a, long b){
    if(b == 0)
    return a;
    else return gcd(b, a % b);
}
long a, b, n;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<gcd(a,b);
    }
    return 0;
}
