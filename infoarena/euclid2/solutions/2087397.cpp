#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream o("euclid2.out");

int cmmdc(int a, int b)
{
    if(!b) return a;
    if(a>b) return cmmdc(a-b,b);
    else return cmmdc(a,b-a);
}

int main()
{
    int i, t, a, b;
    f >> t;
    for(i=0; i<t;i++)
    {
        f >> a >> b;
        o << cmmdc(a, b) << endl;
    }
    return 0;
}
