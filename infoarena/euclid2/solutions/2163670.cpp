#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b)
{int r;
    if(a<b) swap(a,b);
    if(a!=b)
        while(b)
    {
        r=a%b;a=b;b=r;
    }
    return a;
}

int k,a,b;
int main()
{
    f>>k;
   while(k!=0)
   {
    f>>a>>b;
    g<<euclid(a,b)<<endl;
    k--;
   }
    return 0;
}
