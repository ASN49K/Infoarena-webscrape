#include <iostream>
#include <fstream>
using namespace std;
int r,a,b,t,i;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

     f>>t;
     for(i=1;i<=t;i++)
    {f>>a>>b;
     while(b!=0)
     {
         r=a%b;
         a=b;
         b=r;
     }
    g<<endl;
    g<<a;}
    return 0;

}
