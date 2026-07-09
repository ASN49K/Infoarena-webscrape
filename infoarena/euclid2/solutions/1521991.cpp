#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long long a,b,r;
    long T,i;
    f>>T;
    for(i=1;i<=T;i++)
        {f>>a;
        f>>b;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;}

    return 0;
}
