#include<iostream>
#include <fstream>

using namespace std;

long cmmdc(long a, long b)
{
    if(b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main()
{
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");

    long T, i, j, x , y;

    f>>T;

    for(i=1; i<=T; i++)
        {
        f>>x;
        f>>y;
        g<<cmmdc(x,y)<<"\n";
        }



    return 0;
}
