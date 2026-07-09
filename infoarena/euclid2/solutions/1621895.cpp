
#include<iostream>
#include<fstream>

using namespace std;

long int euclid(long int a,long int b)
{
    long int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;

    }
    return a;
}
int main()
{
    long int n,x,y;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>n;
    for(long int i =1;i<=n;i++)
    {
        f>>x>>y;
        g<<euclid(x,y)<<"\n";
    }


    return 0;
}
