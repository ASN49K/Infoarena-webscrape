#include<iostream>
#include <fstream>

using namespace std;

long cmmdc(long a, long b)
{
long m;

 while (b != 0)
    {
    m = a % b;
    a = b;
    b = m;
    }

return a;

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
