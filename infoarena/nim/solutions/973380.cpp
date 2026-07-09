#include <fstream>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t,n,x,xor_sum;

int main()
{
    f>>t;
    for (int j=1; j<=t; j++)
    {
        xor_sum=0;
        f>>n;
        for (int i=1; i<=n; i++)
        {
            f>>x;
            xor_sum^=x;
        }
        if (xor_sum==0) g<<"NU";
        else g<<"DA";
        g<<"\n";
    }
}
