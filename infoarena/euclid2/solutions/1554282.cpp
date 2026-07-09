#include <cstdio>

using namespace std;

int cmmdc(int a,int b)
{
int r;
while(b>0)
{
    r=a%b;
    a=b;
    b=r;
}
return a;

}



int main()
{freopen("euclid2.in","r",stdin);
freopen("euclid2.out","w",stdout);
int t,c,a,b;
scanf("%d",&t);
for(int i=0;i<t;i++){
        scanf("%d,%d",&a,&b);
  c=cmmdc(a,b);
    printf("%d\n",c);
    }

    return 0;
}
