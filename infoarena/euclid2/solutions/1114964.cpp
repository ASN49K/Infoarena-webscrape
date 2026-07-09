#include <iostream>
#include <fstream>
using namespace std;

ifstream d("euclid2.in");
ofstream o("euclid2.out");

int x,y,n,i;
int euclid(int a,int b)
{
    if(!b)
        return a;
    euclid(b,a%b);
}

int main()
{

    d>>n;
    for(i=1;i<=n;i++)
    {
        d>>x>>y;
        o<<euclid(x,y)<<'\n';
    }
    return 0;
}
