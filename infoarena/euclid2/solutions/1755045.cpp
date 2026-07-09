#include <iostream>
#include <fstream>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main ()
{
    int i, n, a, b, r, k=0, v[10001];
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
        k++;
        v[k]=a;
    }

    for (i=1; i<=k; i++)
        out<<v[i]<<'\n';
    return 0;
}
