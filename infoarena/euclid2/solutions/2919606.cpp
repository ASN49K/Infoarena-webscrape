#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int t, a, b;

int Euclid(int a, int b)
{
    if(b==0) return a;
    else return Euclid(b, a%b);
}

int main()
{
    f>>t;

    for(int i=1;i<=t;i++)
    {
        f>>a>>b;

        g<< Euclid(a,b)<<endl;

    }

    return 0;
}
