#include <cstdio>

using namespace std;

int n,sum,x,teste;

int main()
{
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	scanf("%d",&teste);
	for (;teste;teste--)
     {
        sum=0;
        scanf("%d",&n);
		for (int i=1;i<=n;i++)
          {
			 scanf("%d",&x);
             sum^=x;
          }
        if (sum!=0)
		 printf("DA\n");
		else
         printf("NU\n");
     }

}
