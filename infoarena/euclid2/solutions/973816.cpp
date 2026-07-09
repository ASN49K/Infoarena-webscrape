#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int T,i;
long long a,b,c;

int main()
{
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<'\n';
    }
    return 0;
}
