#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    ifstream si("euclid2.in");
    ofstream so("euclid2.out");
    long  contor,a,b,rest;
    si>>contor;
    for(contor;contor;--contor)
    {
            si>>a>>b;
            while (b!=0)
            {
             rest=b%a;
              a=b;
              b=rest;
            }
            so<<a<<"\n";
    }



    return 0;
}
