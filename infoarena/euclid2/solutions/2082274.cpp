#include <iostream>
#include<fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");

int cmmdc(int a, int b)
{
    if(b==0) return a;
    cmmdc(b, a%b);
}
int main()
{
    int t, a, b;
    in>>t;
    for(;t;--t)
    {
        in>>a>>b;
        if(a>b)
            out<<cmmdc(a,b)<<endl;
        else
            out<<cmmdc(b,a)<<endl;
    }
    return 0;
}
