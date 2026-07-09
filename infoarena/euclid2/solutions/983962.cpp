#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,r,b,n,i;
int main()
{
        f>>n;
    for(i=1;i<=n;i++)
    {
    f>>a;
    f>>b;
    while(b)
    {
     r=a%b;
     a=b;
     b=r;
     }

    g<<a<<'\n';
    }
    //cout<<" "<<(x*y)/a<<endl
    return 0;
}
