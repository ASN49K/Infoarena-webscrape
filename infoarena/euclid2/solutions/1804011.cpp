#include <iostream>
#include <fstream>
using namespace std;
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    ifstream f("euclide2.in");
    ofstream g("euclide2.out");
    int n,nr1,nr2;

    f>>n;

    for(int i = 1; i <= n; i++)
    {
        f>>nr1>>nr2;
        g<<euclid(nr1,nr2)<<endl;
    }

    f.close();
    g.close();
    return 0;
}
