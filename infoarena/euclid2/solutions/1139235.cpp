#include<fstream>
using namespace std;
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    int T,a,b;
    fstream f("euclid2.in",ios::in);
    fstream g("euclid2.out",ios::out);
    f>>T;
    for(;T;--T)
    {
        f>>a>>b;
        g<<gcd(a,b)<<endl;
    }
    f.close();
    g.close();
    return 0;
}
