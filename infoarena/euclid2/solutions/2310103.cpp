#include <iostream>
#include <fstream>
using namespace std;
int r,a,b,t,i;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");

     f>>t;
     for(i=0;i<=t;i++)
    {f>>a;
     f>>b;
     while(b!=0)
     {r=a%b;
       a=b;
       b=r;
     }
     g<<a<<endl;}


    return 0;

}
