#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,c=0,a,b,r;
    in>>n;
    while (c<n)
    {
        in>>a>>b;
        c++;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        out<<a<<endl;
    }
    return 0;
}
