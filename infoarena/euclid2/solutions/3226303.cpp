#include<fstream>
#pragma GCC optimize("O3")
std::ifstream fin("euclid2.in");
std::ofstream fout("euclid2.out");
inline int gcd(int a, int b)
{
    if(!b)
        return a;
    return gcd(b, a%b);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    int t, a, b;
    fin>>t;
    while(t--)
    {
        fin>>a>>b;
        fout<<gcd(a, b)<<'\n';
    }
    return 0;
}