#include <fstream>

using namespace std;
ifstream fin("euclid.in");
ofstream fout("euclid.out");
int cmmdc(int a,int b);
int main()
{
    int t,i,a,b;
    fin>>t;
    for (i=1; i<=t; i++) {fin>>a>>b; fout<<cmmdc(a,b)<<'\n';}
    return 0;
}
int cmmdc(int a,int b)
{
    if (!b) return a;
    return cmmdc(b,a%b);
}
