#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int t,a,b,c,r,i;
int main()
{
    f>>t>>a>>b;
    for(i=1;i<=t;i++)
    {
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    g<<a<<endl;
    f>>a>>b;
    }
   }
