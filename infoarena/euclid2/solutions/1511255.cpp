#include <iostream>
#include <fstream>

using namespace std;
    fstream f("euclid2.in") ;
    fstream g("euclid2.out") ;
int euclid(int a, int b)
{   int c=0;

    while(a!=b)
    {
        if(b>a)
{       c=b;
        b=a;
        a=b;
    }
    a=a-b;
    }
g<<a<<endl;
return 0;
}
int main()
{
    int a,t,b,i;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a;
        f>>b;
        euclid(a,b) ;
    }
    return 0;
}
