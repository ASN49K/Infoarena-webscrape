#include <bits/stdc++.h>

using namespace std;

int euclid(int a, int b)
{
    int c;
    while(b)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

int main()
{
    int a, b;
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    in>>a;
    while(in>>a>>b)
        out<<euclid(a, b)<<'\n';
    in.close();
    out.close();
    return 0;
}
