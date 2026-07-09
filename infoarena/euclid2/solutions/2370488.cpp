#include <stdio.h>

using namespace std;
int t,i;
int euclid(int a,int b){
int r;
while(b){
  r=b;
  b=a%b;
  a=r;


}
return a;
}
int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",euclid(a,b));

    }



    return 0;
}
