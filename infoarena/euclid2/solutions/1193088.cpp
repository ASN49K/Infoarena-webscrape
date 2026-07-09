#include <cstdio>

using namespace std;

int T,X,Y;

int cmmdc(int X,int Y)
{
    int R=X%Y;

    while (Y)
    {
      R=X%Y;
      X=Y;
      Y=R;
    }

    return X;
}

int main()
{
freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);

scanf("%d",&T);

while (T--)
{
   scanf("%d%d",&X,&Y);
   printf("%d\n",cmmdc(X,Y));
}

return 0;
}
