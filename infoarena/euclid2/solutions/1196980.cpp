#include <iostream>
#include <fstream>
using namespace std;
int main ()
{
    ifstream si("euclid2.in");
    ofstream so("euclid2.out");
    int  contor,a,b;
    si>>contor;
    for(contor;contor;--contor)
    {
            si>>a>>b;
            while (a!=b)
            {
             if (a>b)
                a=a-b;
              else
                b=b-a;
            }
            so<<a<<"\n";
    }
 
 
 
    return 0;
}