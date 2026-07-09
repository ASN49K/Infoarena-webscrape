#include <iostream>
#include <fstream>

using namespace std;

int algoritmEuclid(int a, int b)
{

    return (!b)?a:algoritmEuclid(b, a%b);

}

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    int t, a, b;

    f >> t;

    while(t--)
    {
        f >> a >> b;
        g << algoritmEuclid(a, b) << endl;
    }

    return 0;
}
