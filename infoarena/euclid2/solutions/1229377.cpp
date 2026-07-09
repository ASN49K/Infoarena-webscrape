#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,a,b;
    freopen("euclid.in","r",stdin);
    freopen("euclid.in","w",stdout);
    scanf("%d",&n);
    while(n!=0)
    {
        scanf("%d %d",&a,&b);
        while(a!=b)
        {
            if(a>b)
                a-=b;
            else b-=a;
        }
        printf("%d\n",a);
        n--;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
