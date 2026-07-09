#include <iostream>
using namespace std;
#include<fstream>
#define mod 666013

int euclid (int a, int b)
{
if (a<b)
    {a=a+b;
    b=a-b;
    a=a-b;}
int d;

    for(int i=1;i*i<b;i++)
        {if (b%i==0)
            {
        if(a%i==0)
            d=i;

        if(a%(b/i)==0)
            return (b/i);}}
    return d;
}
int main ()
{
    int n,a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    while(n)
    {
       f>>a>>b;
       g<<euclid(a,b)<<"\n";
       n--;
    }


    return 0;
}
