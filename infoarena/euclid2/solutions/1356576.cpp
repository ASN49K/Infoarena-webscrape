#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int t,a,b,c;
    f>>t;
    while(t)
    {
        f>>a>>b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<endl;
        t--;
    }

    return 0;
}
