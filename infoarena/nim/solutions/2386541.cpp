#include <cstdio>

using namespace std;

int t;

int n;


void readncheck()
{
    int n;
    scanf("%d\n",&n);
    int N[10009];
    int S=0;

    for(int i=0;i<n;i++)
    {
        scanf("%d ",&N[i]);
        S^=N[i];
    }

    if(S==0)
        {
        printf("NU\n");
        return;
        }

    int bit=1;

    while(bit<S)
        {
        bit<<=1;
        }

    bit/=2;

    for(int i=0;i<n;i++)
    {
        if(bit & N[i])
        {
        printf("DA\n");
        return;
        }
    }
    printf("NU\n");
    return;

}

int main()
{
    freopen("nim.in","r",stdin);
    freopen("nim.out","w",stdout);
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
        readncheck();
    return 0;
}
