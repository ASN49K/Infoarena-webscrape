#include <iostream>
#include <fstream>

using namespace std;


int main()
{


    int a, b, i, d, K=0, t, ok=0, n, j;
    ifstream f ("euclid2.in");
    ofstream g ("euclid2.out");

    f>>n;
    for (j=1; j<=n; j++)
    {
        f>>a;
        f>>b;

    if (a==b)
        {
        g<<a;
        ok=1;
        }

    if (a<b)
    {
        t=a;
        a=b;
        b=t;
    }

        for (i=b; i>=1; i--)
            if (b%i==0&&a%i==0)
            {
            K=K++;
            d=i;

            if (K==1&&ok==0)
            g<<d<<"\n";
            }

    K=0;
    }

    f.close();
    return 0;
}
