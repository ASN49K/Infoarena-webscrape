#include <fstream>

using namespace std;

ifstream cin ("euclid2.in");
ofstream cout ("euclid2.out");

int cmmdc (int a, int b)
{
    int r;
    r=a%b;
    if(r)
    {
        return cmmdc(b,r);
    }
    else
    {
        return b;
    }
}

int main()
{
    int n, a, b;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a >> b;
        cout << cmmdc(a,b);
    }
    return 0;
}
