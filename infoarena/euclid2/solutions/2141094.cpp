#include <iostream>
#include<fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

long long  a,b;
int euclid(int a,int b)
{
    while(a!=b)
    {
        if(a>b)
        a=a-b;
        else
        b=b-a;
    }
    return a;

}
long long n,i;
int main()
{
    f>>n;
    for(i=1; i<=n; i++)
    {
        f>>a>>b;
        g<<euclid(a,b);
        g<<endl;
    }

}
