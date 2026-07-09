#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    long long int t;
    f>>t;
    for(int i=0; i<t; i++)
    {
        long long int a, b;
        f>>a>>b;
        long long int r=a%b;
        while (r>0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        g<<b<<endl;
    }
    f.close();
    g.close();
}
