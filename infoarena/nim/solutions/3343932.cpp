#include <bits/stdc++.h>

using namespace std;

ifstream f("nim.in");
ofstream g("nim.out");

int t,n;

int32_t main()
{
    f>>t;
    for(int tt=1; tt<=t; tt++)
    {
        f>>n;
        int s=0, x;
        for(int i=1; i<=n; i++)
            f>>x, s=s^x;
        if(s==0)
            g<<"NU\n";
        else
            g<<"DA\n";
    }
    return 0;
}
/*


*/
