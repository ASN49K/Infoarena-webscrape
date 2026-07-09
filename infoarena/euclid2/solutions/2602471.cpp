#include <bits/stdc++.h>

using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int main()
{
    int n;
    long long a,b;
    fin >> n;
    while(n)
    {
        n--;
        fin >> a >> b;
        while(b)
        {
            long long c=a%b;
            a=b;
            b=c;
        }
        fout << a << '\n';
    }
    return 0;
}
