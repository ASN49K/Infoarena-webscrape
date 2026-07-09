#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    int N,K;
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
    {
        int rez=0,a;
        scanf("%d",&K);
        for(int i=1;i<=K;i++)
        {
            scanf("%d",&a);
            rez = rez ^ a;
        }
        if(rez==0)
            printf("NU\n");
        else
            printf("DA\n");
    }
    return 0;
}
