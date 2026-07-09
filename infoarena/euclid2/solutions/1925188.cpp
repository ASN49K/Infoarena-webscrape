#include <fstream>
using namespace std;
ifstream f("euclid2.in");ofstream g("euclid2.out");
int a,b,n;
int euclid(int a,int b)
{
    int r = a%b;
    while(r)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
int main()
{
    f >> n;
    for(int i = 1; i <= n; ++i){f >> a >> b; g << euclid(a,b) << '\n';}
    g.close();

    return 0;
}
