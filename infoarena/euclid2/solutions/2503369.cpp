#include<iostream>
#include<fstream>
#include<cstring>
#include<math.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,i,a,b;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
         g<<euclid(a,b)<<"\n";
    }

}
