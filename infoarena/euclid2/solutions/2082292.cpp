#include <iostream>
#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    if(b==0) return a;
    return cmmdc(b, a%b);
}
int main()
{
    int t, a, b;
    for(in>>t;t;--t)
    {
        in>>a>>b;
        out<<cmmdc(a,b)<<'\n';

    }
    return 0;
}
