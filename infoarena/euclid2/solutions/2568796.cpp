#include <bits/stdc++.h>
using namespace std;
ifstream fin ("euclid2.in");
ofstream fout ("euclid2.out");
int n, a, b, i, c;
int main()
{
    fin >> n;
    for(i=1; i<=n; i++)
    {
        fin >> a >> b;
        if(b>a)
            swap(a, b);
        while(b!=0)
        {
            c=a%b;
            a=b;
            b=c;
        }
        fout << a << "\n";
    }
    return 0;
}
