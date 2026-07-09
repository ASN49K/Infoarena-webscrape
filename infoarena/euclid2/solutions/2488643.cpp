#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b;
int main()
{
    f>>n;
    while(f>>a>>b)
    {
        while(a!=b)
        {
            if(a>b)
                a-=b;
            else
                b-=a;
        }
        g<<a<<'\n';
    }
}
