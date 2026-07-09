#include <iostream>
#include <fstream>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int n,a,b,rest,i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        if(a==b) g<<a<<"\n";
        else if(a==1 || b==1) g<<1<<"\n";
        else if(a==0 || b==0) g<<0<<"\n";
        else
        {
            while(b!=0)
            {
                rest=a%b;
                a=b;
                b=rest;
            }
            g<<a<<"\n";
        }
    }
    return 0;
}
