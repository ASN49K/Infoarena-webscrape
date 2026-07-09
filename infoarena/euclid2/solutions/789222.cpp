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

    long T, i, j, x[1000][2];

    f>>T;

    for(i=1; i<=T; i++)
        {
        f>>x[i][1];
        f>>x[i][2];
        g<<cmmdc(x[i][1], x[i][2])<<"\n";
        }



    return 0;
}
