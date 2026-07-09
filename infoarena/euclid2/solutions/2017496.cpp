#include <fstream>

using namespace std;
ifstream in ("euclid2.in");
ofstream out("euclid2.out");

int main()
{
    int n,a,b,r;
    in>>n;
    for (int i=1;i<=n;i++)
    {
        in>>a>>b;
        r=a%b;
        while (r!=0)
        {
            a=b;
            b=r;
            r=a%b;
        }
        out<<b<<'\n';
    }
    return 0;
}
