#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int r,b,a,t,i;
    in>> t;
    for(i=1;i<=t;i++)
    {
        in>> a>> b;
        while(b!=0)
        {
            r = a%b;
            a = b;
            b = r;
        }
        out<<a;
        out<<"\n";
    }
    return 0;
}
