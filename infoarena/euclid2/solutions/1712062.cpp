#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,n,i;
int main()
{
    f>>n;
    for (i=1; i<=n; i++)
    {
        f>>a;
        f>>b;
        while (a!=b)
        {
            if (a>b) a=a-b;
            else b=b-a;
        }
        g<<a<<"\n";    }
    return 0;
}
