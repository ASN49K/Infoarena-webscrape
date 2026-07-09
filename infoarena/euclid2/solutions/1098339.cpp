#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int c,a,b,t;
    f >> t;
    for(int i=1;i<=t;++i)
    {
        f >> a >> b;
        while (b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        g << a << "\n";
    }

}
