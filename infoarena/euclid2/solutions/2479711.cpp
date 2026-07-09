#include <iostream>
#include<fstream>
using namespace std;
long long a,b,t,copie;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    while(t--)
    {
        f>>a>>b;
        long long r=a%b;
        while(r!=0)
        {
            a=b;
            b=r;
            r = a%b;
        }
        g<<b<<'\n';
    }
}
