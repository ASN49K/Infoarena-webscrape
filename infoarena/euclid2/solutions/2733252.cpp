#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");

    int a,b,r,t;
    in>>t;
    while(t--)
    {
        in>>a>>b;

        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }

        if(a == 1)
            a = 0;

        out<<a<<"\n";
    }
    return 0;
}

