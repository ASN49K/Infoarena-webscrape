#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int a,b,t;
    in>>t;
    while(t--)
    {
        in>>a>>b;
        int r;
        while(b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<"\n";
    }
    return 0;
}
