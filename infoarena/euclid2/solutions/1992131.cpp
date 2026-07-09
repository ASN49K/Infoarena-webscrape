#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n,a,b,i,r=1;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;r=1;
        if(a<b)swap(a,b);
        while(a!=b && r!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        g<<a<<'\n';
    }
}
