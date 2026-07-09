#include <fstream>

using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int i,n,a,b,c,r;
int main()
{
    cin >>n;
    for (i=1; i<=n; i++)
    {
        cin >>a>>b;
        while (b!=0)
        {
            r=a%b;
            a=b;
            b=r;
        }
        cout <<a<<'\n';
    }
    return 0;
}
