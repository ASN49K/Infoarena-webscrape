#include<fstream>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int cmmdc(int a, int b)
{
    if(!b) return a;
    return cmmdc(a,a%b);
}
int main()
{
    int t,a,b;
    fin>>t;
    for(;t;--t)
    {
        fin>>a>>b;
        fout<<cmmdc(a,b)<<"\n";
    }
    return 0;
}
