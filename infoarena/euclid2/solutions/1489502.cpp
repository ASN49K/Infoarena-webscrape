#include <iostream>
#include<fstream>
using namespace std;
int cmmdc(long long  a,long long b)
{
    long long c;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}
int main()
{
    int t;
    long long a,b;
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>t;
    for(int i=1;i<=t;i++)
    {
        f>>a>>b;
        g<<cmmdc(a,b)<<"\n";
    }
    f.close();
    g.close();
    return 0;


}
