#include<fstream>
using namespace std;
int T,a,b;
int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
int main()
{
    ifstream f;
    ofstream g;
    f.open ("euclid2.in", ios::in);
    g.open ("euclid2.out", ios::out);
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
