#include <iostream>
#include <fstream>

using namespace std;
int T;
long long int a, b, rest;

int main()
{
    ifstream f ("euclid2.in");
    f>>T;
    ofstream g ("euclid2.out");
    for(int i=1; i<=T; i++)
    {
        f>>a>>b;
        while (b)
        {
            rest=a%b;
            a=b;
            b=rest;
        }
        g<<a<<endl;
    }

    return 0;
}
