#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a ,b ,t;
int main()
{
    f>>a>>b;
    while(b!=0)
    {
        t=b;
        b=a%t;
        a=t;
    }
    if(a==1)
        a=0;
    g<<a;
    return 0;
}
