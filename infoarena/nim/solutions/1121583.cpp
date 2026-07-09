#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int i,t,n;
unsigned long long sumXor,x;
int main()
{
    f>>t;
    while (t--)
    {
        f>>n; sumXor=0;
        for (i=1;i<=n;i++)
        {
            f>>x;
            sumXor^=x;
        }
        if (sumXor) g<<"DA\n";
        else g<<"NU\n";
    }
    return 0;
}
