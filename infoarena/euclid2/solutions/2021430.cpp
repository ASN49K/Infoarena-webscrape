#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int T, a, b, c , i;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=0; i<T; ++i)
    {
        f>>a>>b;
        while (a%b)
        {
            c = a % b;
            a = b;
            b = c;
        }
        g<<b<<'\n';
    }
return 0;
}
