#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a, int b)
{
    if(b==0)
        return a;
    else
        cmmdc(b,a%b);
}

int main()
{
    int a,b;
    int T;

    f >> T;
    for(int i=1; i<=T; i++)
    {
        f >> a >> b;


        g << cmmdc(a,b) << endl;
    }

    return 0;
}
