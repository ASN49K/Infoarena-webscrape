#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid.in");
ofstream g("euclid.out");

int euclid(int a, int b)
{
    while(a != b)
        if(a > b)
            a = a - b;
        else
            b = b - a;
    return a;
}

int main()
{
    int t, a, b, k;
    f >> t;
    for(int  i = 0; i < t; ++i)
    {
        f >> a >> b;
        g << euclid(a,b) << endl;
    }
    return 0;
}
