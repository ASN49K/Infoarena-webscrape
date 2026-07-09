#include <fstream>
std::ifstream f("euclid2.in");
std::ofstream g("euclid2.out");
int j(int a,int b)
{
    return(!a)?b:j(b%a,a);
}
int main()
{
    int n,a,b;
    f>>n;
    while(n--)
        {
            f>>a>>b;
            g<<j(a,b)<<'\n';
        }
}
