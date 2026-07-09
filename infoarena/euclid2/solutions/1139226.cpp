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
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
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
