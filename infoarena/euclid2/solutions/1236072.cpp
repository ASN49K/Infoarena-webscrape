#include<fstream>

using namespace std;

long gcd(int a, int b)
{
    if( a%b == 0 ) return 0;
    else return gcd(b, a%b);
}

int main()
{

        ifstream inFile("euclid2.in");
        ofstream outFile("euclid2.out");

    long x,y;

    inFile >> x >> y;

    outFile << gcd(x,y);

}
