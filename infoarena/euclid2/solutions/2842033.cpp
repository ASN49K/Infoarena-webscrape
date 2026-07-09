#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    long long a,b;
    int T;
    f>>T;
    for(int i=0;i<T;++i)
    {
        f>>a>>b;
        while(a!=b)
        {
            if(a>b)
            {
                a-=b;
            }
            else
            {
                b-=a;
            }
        }
        g<<a<<endl;
    }
}
