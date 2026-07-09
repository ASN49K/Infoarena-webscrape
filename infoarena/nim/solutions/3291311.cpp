#include <fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");
int main()
{
    f.tie(NULL)->ios_base::sync_with_stdio(0);
    int t;
    f>>t;
    while(t--)
    {
        int n,sum=0;
        f>>n;
        for(int i=1;i<=n;i++)
        {
            int x;
            f>>x;
            sum^=x;
        }
        (sum) ? g<<"DA":g<<"NU";
        g<<'\n';
    }
    return 0;
}