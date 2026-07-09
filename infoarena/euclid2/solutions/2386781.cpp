#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
long long euclid (long long a, long long b)
{
    long long r;
    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;

}
int main()
{
    long long a,b,t;
    fin>>t;
    for(int i=0;i<t;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b);
        fout<<'\n';
    }

    return 0;
}
