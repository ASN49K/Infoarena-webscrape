#include <iostream>
#include <fstream>
using namespace std;
int a,b,t;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
inline int cmmdc(int a,int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    fin>>t;;
    // cout<<cmmdc(a,b);
    while(t--)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
