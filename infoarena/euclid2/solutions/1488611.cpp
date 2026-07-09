#include <fstream>
using namespace std;
ifstream fi ("euclid2.in");
ofstream fo ("euclid2.out");
int i,n,a,b;
int main()
{
    fi>>n;
    for (i=1;i<=n;i++)
    {
        fi>>a>>b;
        while (a!=b)
        {
            if (a>b) {a=a-(a/b)*b;if (a==0) a=b;}
            else {b=b-(b/a)*a;if (b==0) b=a;}
        }
        fo<<a<<'\n';
    }
    return 0;
}
