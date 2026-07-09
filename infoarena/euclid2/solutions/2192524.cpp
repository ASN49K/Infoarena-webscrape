#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int T,a,b,rest;
    f >> T;
    for(int i=1;i<=T;i++)
    {
         f >> a >> b;
    while(b)
        {
            rest = a % b;
            a = b;
            b = rest;
        }
    g<<a<<" ";
    g<<endl;
    }

    return 0;
}
