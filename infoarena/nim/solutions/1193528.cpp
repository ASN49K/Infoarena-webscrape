#include <cstdio>

using namespace std;

int T,N,X,Mask;

int main()
{
freopen("nim.in","r",stdin);
freopen("nim.out","w",stdout);

scanf("%d",&T);

while (T--)
{
    scanf("%d",&N);

    Mask=0;
    while (N--)
    {
        scanf("%d",&X);
        Mask=Mask^X;
    }

    (Mask>0) ? printf("DA\n") : printf("NU\n");
}

return 0;
}
