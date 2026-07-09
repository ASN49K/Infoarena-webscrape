#include <bits/stdc++.h>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int main()
{
    int T;
    long long a,b,c;
    f>>T;
    for(int i=1;i<=T;i++)
   {
       f>>a>>b;
    while(b)
    {
        c=a%b;
        a=b;
        b=c;

    }
    g<<a<<endl;
   }

    return 0;
}
