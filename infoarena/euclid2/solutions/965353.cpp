#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
unsigned long long t,a,b;
int main()
{f>>t;
while(t--)
{   f>>a>>b;
    while(a!=b)
    {
        if(a>b) a=a-b;
        else b=b-a;
    }
    g<<a<<'\n';

}
    return 0;
}
