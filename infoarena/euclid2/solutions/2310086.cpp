#include <iostream>
#include <fstream>
using namespace std;
int r,a,b;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

     f>>a>>b;
     while(b!=0)
     {
         r=a%b;
         a=b;
         b=r;
     }

    g<<a;
    return 0;

}
