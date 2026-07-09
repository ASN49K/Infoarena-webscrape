#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream in("euclid2.in");
    ofstream out("euclid2.out");
    int n,c=0,a,b,d;
    in>>n;
    while (c<n)
    {
        in>>a>>b;
        c++;
        while (a!=b)
        if (a>b)
            a-=b;
        else
            b-=a;
        out<<a<<endl;
    }
    return 0;
}
