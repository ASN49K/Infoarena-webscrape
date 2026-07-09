
#include <fstream>
using namespace std;
int cmmdc(int a, int b)
{
    int r;
    r=a%b;
    if(r)
        return cmmdc(b,r);
    else
        return b;
}
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int main()
{
    int t,a,b;
    fin>>t;
    for(;t;t--){
    fin>>a>>b;
    fout<<cmmdc(a,b)<<"/n";
}
    return 0;
}
