#include <bits/stdc++.h>
#define in "euclid2.in"
#define out "euclid2.out"

using namespace std;

ofstream fout(out);

int n;

int main()
{
    freopen(in,"r",stdin);
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        while(b)
        {
            int r=a%b;
            a=b;
            b=r;
        }
        fout<<a<<'\n';
    }

    return 0;
}
