#include <iostream>
#include <fstream>
using namespace std;

int a,b,t,r;


ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    f>>t;
    for(int i=1; i<=t; i++)

    {

     f>>a>>b;

        while(a%b!=0)

        {
        r=a%b;
        a=b;
        b=r;
        }
        g<<b<<endl;

    }




    return 0;
}
