#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    long long int a, b;
    int t;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

    f>>t;
    for(int i=1; i<=t; i++)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(a>b) a-=b;
            else if(b>a) b-=a;
        }
        g<<a<<"\n";
    }
    return 0;
}
