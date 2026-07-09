#include <bits/stdc++.h>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int n,a,b;
int main()
{
    cin>>n;
    while (n)
        {
            fin>>a>>b;
            fout<<__gcd(a,b)<<"\n";
            n--;
        }
    return 0;
}
