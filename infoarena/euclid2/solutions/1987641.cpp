#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int i,n,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for (i=1;i<=n;i++)
    {
        int c;
        f>>a>>b;
        while(b)
        {
            c=a%b;
            a=b;
            b=c;
        }
        g<<a<<"\n";
    }
    return 0;
}
