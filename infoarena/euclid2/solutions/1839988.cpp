#include <iostream>
#include<fstream>
using namespace std;
ifstream f1("euclid2.in");
ofstream f2("euclid2.out");
int main()
{
    int t,a,b,r,i;
    f1>>t;
    for(i=1; i<=t; i++)
    {
        f1>>a>>b;
        while(b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        f2<<a<<"\n";
    }

    return 0;
}
