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
    int a,b,t,i,c;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>t;
    for(i=1;i<=t;i++)
    {
        in>>a>>b;
        c=euclid(a,b);
        out<<c<<endl;
    }
    in.close();
    out.close();
    return 0;
}
