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
        long long int r;
        while (b>0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;
    }
    f.close();
    g.close();
}
