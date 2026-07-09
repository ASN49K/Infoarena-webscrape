#include<fstream>
using namespace std;

int t, a, b;

int cmmdc(int a, int b)
{int r;
if(b==0 || a==b) return a;
for(;;)
   {r=a%b;
    a=b;
    if(r==0) return b;
    b=r;
   }
}

int main()
{freopen("euclid2.in", "r", stdin);
freopen("euclid2.out", "w", stdout);
scanf("%d", &t);

for(; t; t--)
   {scanf("%d%d", &a, &b);
    printf("%d\n", cmmdc(a, b));
   }

return 0;
}
