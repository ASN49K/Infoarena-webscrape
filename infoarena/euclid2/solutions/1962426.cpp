#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b)
{
    if (b==0) return a;
    else gcd(b,a%b);

}

int main()
{


    int a, b, i, div, nr;
    ifstream f;
    ofstream g;

    f.open("euclid2.in");
    g.open("euclid2.out");

    f>>nr;

    for(i=0;i<nr;i++)
    {
        f>>a;
        f>>b;
        div=gcd(a,b);

        g<<div<<"\n";

    }

    f.close();
    g.close();


    return 0;
}
