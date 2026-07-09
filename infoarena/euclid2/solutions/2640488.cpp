#include <fstream>
#include <iostream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,c,t;
int main()
{
    f>> t;
    while(t != 0)
    {
        f >> a >> b;
        c = a % b;
        while(c != 0)
        {
            a = b;
            b = c;
            c = a % b;
        }
        g << b << '\n';
        t--;
    }
    return 0;

}
