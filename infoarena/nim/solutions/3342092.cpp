#include <bits/stdc++.h>
using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main()
{
    int t;
    in >> t;
    while(t--)
    {
        int n;
        in >> n;
        int xor_gramezi=0;
        for(int i=1; i<=n; i++)
        {
            int a;
            in >> a;
            xor_gramezi^=a;
        }
        if(xor_gramezi==0) out << "NU\n";
        else out << "DA\n";
    }

    return 0;
}
