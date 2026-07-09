#include <bits/stdc++.h>

using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int n;
struct {
    int x,y;
}v[100005];
int euclid(int a,int b)
{
    int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;

}
int main()
{
    f>>n;
    for(int i=1;i<=n;i++)
    {
        f>>v[i].x>>v[i].y;
        g<<euclid(v[i].x,v[i].y)<<" ";
        g<<"\n";
    }
    return 0;
}
