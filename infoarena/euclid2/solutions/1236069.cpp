#include<fstream>

using namespace std;

long gcd(int a, int b)
{
    long R;
    while(b!=0)
    {
        R=a%b;
        a=b;
        b=R;
    }
    return (a);
    }
int main()
{

        ifstream inFile("euclid2.in");
        ofstream outFile("euclid2.out");

    long x,y;

    inFile >> x >> y;

    outFile << gcd(x,y);
return 0;
}
