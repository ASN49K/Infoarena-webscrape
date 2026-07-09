#include <fstream>
std::ifstream i("euclid2.in");
std::ofstream o("euclid2.out");
int cmmdc(int a,int b)
{
    return b==0?a:cmmdc(b,a%b);
}
main()
{
    int n,a,b;
    i>>n;
    while(n--)
    {
        i>>a>>b;
        o<<cmmdc(a,b)<<'\n';
    }
}
