#include <bits/stdc++.h>
#define DIM 100010
using namespace std;
typedef long long ll;
ifstream fin("euclid2.in");
ofstream fout("euclid2.out");
int n,a,b;

int euclid (int a,int b)
{
    if(a<b)
        swap(a,b);
    while(b!=0)
    {
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>a>>b;
        fout<<euclid(a,b)<<'\n';
    }
    return 0;
}
