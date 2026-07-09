#include        <bits/stdc++.h>

using    namespace        std;

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

int main()
{
    ios_base::sync_with_stdio(false);
                       cin.tie(NULL);

    int T; in >> T;

    for(int i = 0; i < T; i++)
    {
        int a, b, r = 0;
        in >> a >> b;
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        out << a << endl;
    }

    in.close(); out.close();

    return 0;
}