#include <fstream>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int T,a,b;
int gcd(int a,int b)
{
    if (b!=0)
        return a;
    return gcd(b,a%b);
}

int main(void)
{
    fin>>T;
    while(T--)
    {
        fin>>a>>b;
        fout<<gcd(a,b);
    }
    return 0;
}
