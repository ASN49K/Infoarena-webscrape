#include <bits/stdc++.h>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int main()
{
    int a,b,T;
    int k;
    f>>T;
    int i;
    vector<int>v;
    for(i=0;i<T;++i)
    {
        f>>a>>b;
        if(a>b)
        {
            for(int j=1;j<=b;++j)
            {
                if(a%j==0 && b%j==0)
                {
                    k=j;
                }
            }
            v.push_back(k);
        }
        if(b>a)
        {
            for(int j=1;j<=a;++j)
            {
                if(a%j==0 && b%j==0)
                {
                    k=j;
                }
            }
            v.push_back(k);
        }
    }
    for(int k=0;k<v.size();++k)
    {
        g<<v[k]<<endl;
    }
}
