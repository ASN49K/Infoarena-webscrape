#include <fstream>
std::ifstream in("euclid2.in");
std::ofstream out("euclid2.out");
int cmmdc(int a , int b)
{
    return b==0?a:cmmdc(b,a%b);
}
int main()
{
    int n, a, b;
    in >> n;
    while(n--)
    {
        in >> a >> b;
        out << cmmdc(a,b) << '\n';
    }
    return 0;
}
