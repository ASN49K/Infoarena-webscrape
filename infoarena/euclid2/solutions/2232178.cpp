#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int a,b,t;
int cmmdc(int a, int b){
    if(!b)return a;
    return cmmdc(b, a%b);
}
int main()
{
    f>>t;
    for(int i=1 ; i<=t ; ++i){
        f>>a>>b;
        g<<cmmdc(a,b)<<'\n';
    }
    return 0;
}
