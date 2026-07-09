#include <iostream>
#include <fstream>
using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    while(b != 0)
    {
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,x,y;
    in>>n;

    for(int i=0; i<n; i++)
        {
            in>>x>>y;
            out<<cmmdc(x,y)<<'\n';
        }

    return 0;
}
