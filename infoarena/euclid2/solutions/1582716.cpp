#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int cmmdc_Euclid(int a, int b)
{
    int r;
    while(b!=0){
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int t,a,b;
    f>>t;
    for(int i=1;i<=t;++i){
        f>>a>>b;
        g<<cmmdc_Euclid(a,b)<<'\n';
    }
    f.close();
    g.close();
    return 0;
}
