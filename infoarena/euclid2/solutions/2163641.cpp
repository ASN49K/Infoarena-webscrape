#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b)
{
    if(a==b) return a;
    if(a!=b)
        while(a!=b)
    {
        if(a>b) a=a-b; else b=b-a;
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
