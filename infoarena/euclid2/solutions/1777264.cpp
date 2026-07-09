#include <fstream>
#include <iostream>

using namespace std;

ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int t, nr1, nr2, mamaliga;

int main()
{
    in >> t;
    for(; t > 0; --t)
    {
        in >> nr1 >> nr2;

        while(nr2 != 0)
        {
            mamaliga = nr2;
            nr2 = nr1 % nr2;
            nr1 = mamaliga;
        }
        out << nr1 << "\n";
    }
}
