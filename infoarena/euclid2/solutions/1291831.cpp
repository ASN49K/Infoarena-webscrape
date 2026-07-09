#include<fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a, int b)
{
    int c;
    while (b) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int a,b,n;
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<euclid(a,b)<<'\n';
    }
return 0;
}
