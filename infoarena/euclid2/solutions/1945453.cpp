#include <iostream>
#include <fstream>
using namespace std;
long long a,b,t;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for (int i=1;i<=t;i++)
    {
        f>>a>>b;
        if ((a>b) and (a%b==0)) g<<b<<"\n";
        else if ((a<b) and (b%a==0)) g<<a<<"\n";
        else if (a>b) g<<a%b<<"\n";
        else g<<b%a<<"\n";
    }
    return 0;
}
