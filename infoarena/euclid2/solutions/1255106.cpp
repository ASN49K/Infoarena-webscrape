#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
    int a,b,n;
    in>>a>>b;

    int r=a%b;
    while(r!=0)
    {
        a=b;
        b=r;
        r=a%b;
    }
    a=b;
    out<<a;
    return 0;
}

