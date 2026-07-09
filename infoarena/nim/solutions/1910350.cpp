#include <cstdio>

using namespace std;
int x,n,numere;

void read()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d",&x);
    for(int i = 0 ; i < x ; i++)
    {
        scanf("%d", &n);
        numere = 0;
        for(int j = 0 ; j < n ; j++)
            {
                int y ;
                scanf("%d",&y);
                numere^=y;
            }
        if(numere == 0)
            printf("NU\n");
        else
            printf("DA\n");
    }
}

int main()
{
    read();
    return 0;
}
