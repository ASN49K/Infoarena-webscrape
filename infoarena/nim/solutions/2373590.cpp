#include <bits/stdc++.h>

using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int n,t;
int main()
{
    in >> t;
    int xr=0;
    while(t--)
    {
        in >> n;
        xr=0;
        while(n--)
        {
            int x;
            in >> x;
            xr^=x;
        }
        if(xr) out << "DA\n";
        else out << "NU\n";
    }
    return 0;
}
