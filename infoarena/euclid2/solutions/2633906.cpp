#include <iostream>
#include <fstream>

using namespace std;

ifstream i("euclid2.in");
ofstream o("euclid2.out");

int main()
{
     unsigned int t, a, b;
    i>> t;
    while(t--)
    {
        i>> a >> b;
        while(b!=0)
        {
            int r = a%b;
            a = b;
            b = r;
        }
        o<<a << endl;

    }
    return 0;
}
