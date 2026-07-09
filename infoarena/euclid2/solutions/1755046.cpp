#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main ()
{
    int i, n, a, b, r, k=0, v[100001];
    in>>n;
    for (i=1; i<=n; i++)
    {
        in>>a>>b;
        while (b)
        {
            r=a%b;
            a=b;
            b=r;
        }
        out<<a<<'\n';
    }


    return 0;
}
