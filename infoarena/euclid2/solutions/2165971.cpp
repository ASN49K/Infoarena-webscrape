#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");


int k,a,b,r;
int main()
{
    f>>k;
    while(k)
    {
        f>>a>>b;
        if(a==b) g<<a<<endl;
        else
        {
            while(b>0)
        {
            r=a%b;a=b;b=r;
        }
        g<<a<<endl;
        }
        k--;
    }


    return 0;
}
