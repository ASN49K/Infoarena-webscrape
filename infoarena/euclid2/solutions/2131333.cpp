#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    if(b== 0)
        return a;
    return cmmdc(b,a%b);
}
int main()
{
    int t,x,y;
    in >> t;
    for(int i = 0 ; i < t ; i++)
    {
        in>> x >>  y;
        out<<cmmdc(x,y)<<'\n';
    }
    return 0;
}
