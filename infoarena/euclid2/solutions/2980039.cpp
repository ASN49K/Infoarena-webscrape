#include <bits/stdc++.h>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int euclid(int a,int b)
{
    if(b==0)return a;
    return euclid(b,a%b);
}

int main()
{
    int t,a,b;
    f>>t;
    for(int i=1;i<=t;i++)
        {f>>a>>b;g<<euclid(a,b)<<endl;}

}
