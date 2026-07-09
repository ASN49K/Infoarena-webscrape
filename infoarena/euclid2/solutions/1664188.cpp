#include <fstream>
using namespace std;
ifstream in ("euclid2.in");
ofstream out ("euclid2.out");
int GCD(int A, int B)
{
    if(!B)
        return A;
    return GCD(B, A%B);
}
int main ()
{
    int n,a,b,i;
    in>>n;

    for (i=1;i<=n;i++)
    {
        in>>a>>b;
        out<<GCD(a,b)<<endl;

    }

return 0;}
