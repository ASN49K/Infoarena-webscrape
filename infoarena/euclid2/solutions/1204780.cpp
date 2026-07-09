#include <iostream>
#include <fstream>
using namespace std;
long long a,b,T;
int i,d;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    for(i=0;i<T;i++)
    {
        d=0;
        f>>a>>b;
        while(b)
        {
            d=a%b;
            a=b;
            b=d;
        }
        g<<a<<'\n';
    }
    return 0;

}
