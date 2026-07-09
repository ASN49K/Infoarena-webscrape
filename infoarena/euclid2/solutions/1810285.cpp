#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int rec(int a,int b)
{
    if(a%b==0)
        return b;
    if(b%a==0)
        return a;
    if(a>b)
        return rec(a-(a/b)*b,b);
    return rec(a,b-(b/a)*a);
}
int t,a,b;
int main()
{
    fin>>t;
    while(t)
    {
        fin>>a>>b;
        fout<<rec(a,b)<<"\n";
        t--;
    }
    return 0;
}
