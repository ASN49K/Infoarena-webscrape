#include <bits/stdc++.h>
using namespace std;
ifstream in("nim.in");
ofstream out("nim.out");
int main()
{
    int t, n;;
    in >> t;
    while(t)
    {
        t --;
        in >> n;
        int nr = 0;
        for(int i = 1; i <= n; i++)
        {
            int a;
            in >> a;
            nr ^= a;
        }
        if(nr)
            out << "DA" << '\n';
        else
            out << "NU" << '\n';
    }
    return 0;
}
