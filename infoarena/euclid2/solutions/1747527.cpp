#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

long gcd(long a, long b)
{
    a = abs(a);
    b = abs(b);
    return ( b == 0 ) ? a : gcd(b,a%b);
}

int main()
{
    int nrQueries = 0,a,b;

    ifstream inFile("euclid2.in");
    ofstream outFile("euclid2.out");

    if(!inFile.is_open())
    {
        outFile<<"Y U No Provide files?";
        outFile.close();
        return 0;
    }

    inFile>>nrQueries;
    while(nrQueries > 0)
    {
        inFile>>a>>b;
        nrQueries--;
        outFile<<gcd(a,b)<<endl;
    }

    inFile.close();
    outFile.close();
    return 0;
}
