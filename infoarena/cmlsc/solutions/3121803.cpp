#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int euclid(int a,int b)
{
    cout<<a<<" "<<b<<endl;
    if(b==0)
        return a;
    return euclid(b,a%b);
}
int main()
{int n;

f>>n;
for(int i=1;i<=n;i++)
{
    int a,b;
    f>>a>>b;
    g<<euclid(a,b)<<'\n';
}

    return 0;
}
