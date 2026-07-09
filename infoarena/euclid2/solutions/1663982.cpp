#include <fstream>
using namespace std;
ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");
int main ()
{
    int n, a, b,r, v[100], i;
    cin>>n>>a>>b;
    for (i=1; i<=n; i++) v[i];
    for (i=1; i<=n; i++)
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    cout<<a<<endl;
}
