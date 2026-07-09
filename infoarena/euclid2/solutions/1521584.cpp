#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int a,int b)
{
    if(a%b)
        return cmmdc(b,a%b);
    return b;
}
int main()
{
    int a,b;
    f>>a>>b;
    cout<<cmmdc(a,b);
    f.close();
    g.close();
}
