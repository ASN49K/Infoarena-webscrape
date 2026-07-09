#include <bits/stdc++.h>
using namespace std;

int euclid(int a,int b)
{
    if(a==0) return b;
    else return euclid(b%a,a);
}

int main()
{
    int m,a,b;
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&m);
    for(;m;m--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
