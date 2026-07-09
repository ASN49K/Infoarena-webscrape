#include <iostream>
#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
long long t, a, b;
int cmmdc(int a, int b)
{
    if(b==0)return a;
    else return cmmdc(b,a%b);


}
int main()
{   f>>t;
    for(int i=1; i<=t; i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<endl;
    }
    return 0;
}
