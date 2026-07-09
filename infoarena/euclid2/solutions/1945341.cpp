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
        while (a!=b)
        {
            if (a>b) a=a-b;
            else b=b-a;
        }
        g<<a<<"\n";
    }
    return 0;
}
