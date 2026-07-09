#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    long long a,b;
    int t;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=1;i<=t;++i)
    {
        f>>a>>b;
        while(b)
        {
            int c;
            c=b;
            b=a%b;
            a=c;
        }
        g<<a<<"\n";
    }
    return 0;
}
