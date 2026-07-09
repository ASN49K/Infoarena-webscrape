#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int t, a, b, c;
    in>>t;
    for(;t;t--)
    {
        in>>a>>b;
        while(b)
        {
            c=b;
            b=a%b;
            a=c;
        }
        out<<a<<"\n";
    }
    return 0;
}
