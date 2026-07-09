#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    return cmmdc(b,a%b);
}

int main()
{
    ifstream f("euclid2.in");
    ofstream o("euclid2.out");
    int a,b,n;
    f>>n;
    for(;n;--n)
    {
    f>>a>>b;
    o<<cmmdc(a,b)<<endl;
    }
}
