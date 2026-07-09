#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int i, nr, t;
    long a,b;
    ifstream f;
    ofstream g;

    f.open("euclid.in");
    g.open("euclid.out");

    f>>nr;

    for(i=0;i<nr;i++)
    {
        f>>a;
        f>>b;
      //  div=gcd(a,b);
        while(b)
        {
            t = a%b;
            a = b;
            b = t;
        }


        g<<a<<"\n";

    }
    f.close();
    g.close();

    return 0;
}
