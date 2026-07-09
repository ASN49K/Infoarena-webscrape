#include<iostream>
#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a , int b)
{
    int r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;

    }
    return a;
}
int main()
{
    int a,b,T;
    f>>T;
    for(;T;--T)
    {
        f>>a>>b;
        fout<<cmmdc(a,b)<<endl;
    }
}
