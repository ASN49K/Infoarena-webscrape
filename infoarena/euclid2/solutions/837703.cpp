#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int a, b, T, r;
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");
    f>>T;
    for(int i=1;i<=T;i++)
    {
        f>>a;
        f>>b;
        r=0;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<endl;
    }
    return 0;
}
