#include <cstdio>
#define lim 5000
#define MAX(a,b) a>b?a:b
using namespace std;


int weight[lim];
int price[lim];
int maxWeight;
int s1[2*lim+5],s2[2*lim+5];
int n;
int solve()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 1; j<=maxWeight;j++)
        {
            s1[j] = s2[j];
            if(weight[i] <= j)
            {
                s2[j] = MAX(s1[j], s1[j-weight[i]] + price[i]);
            }
        }
    }
    return s2[maxWeight];
}

int main()
{
    freopen("rucsac.in","r",stdin);
    //freopen("rucsac.out","w",stdout);

    scanf("%d %d",&n,&maxWeight);
    for(int i =0; i < n ; i++)
    scanf("%d %d",&weight[i],&price[i]);
    printf("%d",solve());



    return 0;
}
