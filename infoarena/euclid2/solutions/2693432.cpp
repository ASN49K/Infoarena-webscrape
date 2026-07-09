#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a,int b)
{
    if(a==b)
        return a;
    if (a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
}

int main()
{
    fstream f("euclid2.in",fstream::in);
    fstream g("euclid2.out",fstream::out);

    int T,a,b;
    f>>T;

    while(T>0)
    {
        f>>a>>b;
        T--;
        g<<gcd(a,b)<<endl;
    }

    return 0;
}
