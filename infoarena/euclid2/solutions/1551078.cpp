#include <bits/stdc++.h>
using namespace std;
int euclid(int a, int b)
{
    int c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
    int a,b,t,i;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        out<<euclid(a,b)<<endl;
    }
    in.close();
    out.close();
    return 0;
}
