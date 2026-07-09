#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    ifstream si("euclid2.in");
    ofstream so("euclid2.out");
    int  contor,a,b,rest;
    si>>contor;
    for(contor;contor;--contor)
    {
            si>>a>>b;
            while (b!=0)
            {
             rest=a%b;
              a=b;
              b=rest;
            }
            so<<a<<"\n";
    }



    return 0;
}
