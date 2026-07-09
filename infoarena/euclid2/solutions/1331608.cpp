#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long a ,b ,t ,n ,i;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
    f>>a>>b;
    while(b!=0)
    {
        t=b;
        b=a%t;
        a=t;
    }
    g<<a<<'\n';
    }
    return 0;
}
