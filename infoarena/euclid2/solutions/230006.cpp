#include<fstream>
using namespace std;

ifstream f ("euclid2.in");
ofstream g ("euclid2.out");
int n,i,a,b;

int cmmdc(int m, int n)
{
    if(!n) return m;
    return cmmdc(n,m%n);
}

int main()
{
    f>>n;
    for(i=0;i<n;i++) f>>a>>b,g<<cmmdc(a,b)<<"\n";
    f.close();
    g.close();
    return 0;
}

