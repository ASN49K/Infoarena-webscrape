#include <iostream>
#include <fstream>

using namespace std;

ifstream cn("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int t, a, b;
    cn>> t;
    while(t>0)
    {
        t--;
        cn>> a >> b;
        while(b>0)
        {
            int r = a%b;
            a = b;
            b = r;
        }
        g<< a<<endl;

    }
    return 0;
}
