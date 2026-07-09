#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long long a,b,r;
    long T;
    f>>T;
    for(;T;T--)
        {f>>a;
        f>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;}

    return 0;
}
