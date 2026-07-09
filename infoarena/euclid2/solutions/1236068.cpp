#include<fstream>

using namespace std;

int gcd(int a, int b)
{
    int R;
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

    int x,y;

    inFile >> x >> y;

    outFile << gcd(x,y);
return 0;
}
