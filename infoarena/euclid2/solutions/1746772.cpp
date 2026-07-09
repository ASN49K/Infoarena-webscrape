#include <iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc(int A,int B)
{
    int R;
    while(B!=0)
    {
        R=A%B;
        A=B;
        B=R;
    }
    return A;
}
int main()
{
    int T,a,b,i;
    f>>T;
    for(i=1;i<=T;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
