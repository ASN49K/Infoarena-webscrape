#include <iostream>
#include <fstream>
using namespace std;
int i,a,b;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
void cmmdc(int a,int b)
{
    if(b==0)g<<a<<endl;
    else cmmdc(b,a%b);
}
int main()
{
    int t;
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>a>>b;
        cmmdc(a,b);
    }
    return 0;
}
