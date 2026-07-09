#include<bits/stdc++.h>
using namespace std;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int euclid(int a, int b)
{
    if(b==0)
        return a;
    return euclid(b,a%b);
}
int main()
{
    int n,a,b;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        euclid(a,b);
        fout<<euclid(a,b)<<endl;
    }

    return 0;
}
