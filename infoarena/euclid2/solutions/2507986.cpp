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
        r = a % b;
        while(r != 0)
        {
           a = b;
           b = r;
           r = a % b;
        }
        out<<b<<endl;
    }
    return 0;
}
