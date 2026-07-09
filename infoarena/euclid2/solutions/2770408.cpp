#include        <bits/stdc++.h>

using           namespace          std;

#define  ui     unsigned           int
#define  us     unsigned short     int
#define ull     unsigned long long int
#define  ll              long long int
#define  lf                     double
#define llf              long   double
#define  PI                 3.14159265
#define INF                 0x7fffffff

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int euclid(int a, int b)
{
    if(b == 0)
        return a;
    else
        return euclid(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
                       cin.tie(NULL);

    int T; in >> T;

    while(T--)
    {
        int a, b;
        in >> a >> b;

        out << euclid(a, b) << endl;
    }

    in.close(); out.close();

    return 0;
}